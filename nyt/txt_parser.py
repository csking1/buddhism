
import glob
import os
import csv
import codecs
import string
# import ntlk
# nltk.download()

def read_files():

	os.chdir("/home/csking1/buddhism/nyt")
	for file in glob.glob("*.txt"):
		for line in open(file):
			print (line)
		


if __name__ == '__main__':		

	read_files()

