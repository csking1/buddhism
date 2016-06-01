import glob
import os
import csv
import codecs
import string
# import ntlk
# nltk.download()
from nltk.corpus import stopwords
import random


def clean_word(word):
    word = word.lower()
    for each in [",", ";", ":", "!", ".", "?", "-"]:
        if each in word:
            word = word.replace(each, "")
    if len(word) >= 1:
        return word
    return None


def send(out):
    '''
    Takes a list of cleaned words, randomly picks a file between one and 16
    And appends the list to the file.
    '''
    f = "GutenFiles/file_{}.txt"
    i = random.randint(1,16)
    s = " ".join(out)
    with open(f.format(i), "a") as f:
        f.write(s + "\n")

def read_files():
    stop = stopwords.words("english")
    os.chdir("/home/ec2-user/gutenberg_text/clean")
    for file in glob.glob("*.txt"):
        # if file is not english:
        with open(file, "r") as f:
            for line in f.readlines():
                out = []
                sentence = line.split()
                for word in sentence:
                    word = clean_word(word)
                    if (word is not None) and (word not in stop):
                        out.append(word)
            send(out)

if __name__ == '__main__':
    send(["please", "write", "to", "this", "file"])
