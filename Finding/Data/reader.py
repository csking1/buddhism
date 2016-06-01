import sys

# get rid of some stopwords here

def process(filename, label):
	'''
	Walks through the text file and adds everything to one gigantic string
	Walks through the string, looking for punctuation, and sends the split to the printer
	'''
	# add everything to one gigantic string, then walk through it and pick up sentences
	gigantic = " "
	punctuation = ["?", "!", "."]

	with open(filename, "r") as f:
		for l in f.readlines():
			a = l.strip("\n")
			gigantic += a

	last = 0
	for i, s in enumerate(gigantic):
		if s in punctuation:
			string = gigantic[last:i+1]
			print ("{} {}".format(string, label))
			last = i+1


if __name__ == "__main__":
	process(sys.argv[1], sys.argv[2])