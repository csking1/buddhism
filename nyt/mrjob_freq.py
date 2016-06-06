from mrjob.job import MRJob
import re

WORD_RE = re.compile(r"[\w']+")


class MRWordFreqCount(MRJob):

    def mapper(self, _, line):
        for word in WORD_RE.findall(line):
            yield 1

    def combiner(self, counts):
        yield sum(counts)

    def reducer(self, counts):
        yield sum(counts)


if __name__ == '__main__':
    MRWordFreqCount.run()