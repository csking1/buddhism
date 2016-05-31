# if there are no empty spaces, skip it
# check for punctuation and remove
# remove stopwords

import sys
# import nltk
# nltk.download()
from nltk.corpus import stopwords


def clean_word(letter):
	for each in ["(", ".", ',', ")"]:
		if each in letter:
			letter = letter.replace(each, "")
	if len(letter) == 0:
		return None
	return letter


def process(filename):
	'''
	Reads in each line from the text file, tokenizes the sentence,
	Looks for stop words, sends results to main training text file
	'''

	stop = stopwords.words('english')
	stop.append(None)
	with open(filename, "r") as f:
		for l in f.readlines():
			out = []
			for c in l.split():
				s = clean_word(c)
				if s not in stop:
					out.append(s)
			print (out)

if __name__ == "__main__":
	process(sys.argv[1])