
import glob
import os
import csv
import codecs
import string
# import ntlk
# nltk.download()

def read_files():

	os.chdir("/home/ec2-user/gutenberg_text")
	for file in glob.glob("*.txt"):
		with open(file, "r") as f:
			print (f.readline())
		

if __name__ == '__main__':		

	read_files()

