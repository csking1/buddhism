import sys
# import nltk
# nltk.download()
from nltk.corpus import stopwords


def clean_word(letter, filename):
	letter = letter.lower()
	if "trump" not in filename:
		for each in ["(", ".", ',', ")", "'"]:
			if each in letter:
				letter = letter.replace(each, "")
		if len(letter) <= 1:
			return None
		return letter

	for each in ["?", "-", ":", "cheers", "applause", "(", ")", ".", ",", "'", '"', "--", ";"]:
		if each in letter:
			letter = letter.replace(each, "")
	if len(letter) <= 1:
			return None
	return letter


def process(filename, label):
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
				s = clean_word(c, filename)
				if s not in stop:
					out.append(s)
			if len(out) > 1:
				out.append(label)
				print (" ".join(out))

if __name__ == "__main__":
	process(sys.argv[1], sys.argv[2])