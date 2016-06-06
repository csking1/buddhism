from mrjob.job import MRJob
import re

WORD_RE = re.compile(r"[\w]+")

class MRTotalWords(MRJob):

  def mapper(self, _, line):
    for word in WORD_RE.findall(line):
      yield None, 1
  
  def combiner(self, _, counts):
    yield None, sum(counts)
  
  def reducer(self, _, counts):
    yield None, sum(counts)

if __name__ == '__main__':
  MRTotalWords.run()