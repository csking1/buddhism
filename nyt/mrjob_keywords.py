

##use python2
from mrjob.job import MRJob
import re
import heapq

K = 10
WORD_RE = re.compile(r"[\w']+")

class MR_top_kwords(MRJob):

    def mapper(self, _, line):
        for word in WORD_RE.findall(line):
            yield word.lower(), 1

    def combiner(self, word, counts):
        yield word, sum(counts)

    def reducer_init(self):
    	self.top_k = [(0, 0)] * K

    def reducer(self, word, counts):
    	c = sum(counts)
    	if c > self.top_k[0][0]:
    		heapq.heapreplace(self.top_k, (c, word))
    def reducer_final(self):
    	final = sorted(self.top_k)
    	for val, word in final:
    		yield val, word



if __name__ == '__main__':
    MR_top_kwords.run()