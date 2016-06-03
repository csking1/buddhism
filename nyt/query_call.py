
## query_call.py receives a CSV of Gutenberg quotes from various texts 
## Each quote is accompanies with a decimal between 0 and 1 designating how well the 
## Quote scored on a NLP machine learning algorithm trained with Buddhist Quotes, with 0 designating that
## the quote did not do well and 1 designating the highest score for a possible Buddhist quote. 

from articles import go
import csv
import chardet
import re

# key = "01f2b56924bc493e87d25177ef24a697"
key = '&api-key=7e90712233444f859a2b6bfe175ed4c1'
QUART_DICT = {.25:[],.5:[],.75:[], 1:[]}
DATES = {.25:[],.5:[],.75:[], 1:[]}
NO_RETURN = 0
OUTPUT_DIRECTORY = "/home/ec2-user/gutenberg_text/python_output/"

def main(filename):
	'''
	Takes in output csv from Gutenberg scraping/Naive Bayes Algorithm 
	on how "Buddhist" each quote is. 
	Note: Chardet is used to circumvent text encoding ISO-8859-2
	'''
		
	with open(filename, 'r') as f:
		for line in f.readlines():
			prob = re.findall("\d+\.\d+", line)
			if len(prob) != 0:
				length = len(prob[0])
				threshold = float(prob[0])
				quote = line[length + 2:]
				print (quote)
				bucket = get_bucket(threshold)
				while counter <= 100:
					try:
						get_keywords(quote, bucket)
						counter = 0
					except:
						counter += 
						

	convert_dict_to_csv()

def get_bucket(threshold):
	'''
	Takes quote threshold and returns quartile bucket for dictionary with inclusive lower-boundary
	'''
	bucket = 0
	if 0 <= threshold < .25:
		bucket = .25
	if .25 <= threshold < .5:
		bucket = .50
	if .5 <= threshold < .75:
		bucket = .75
	if .75 <= threshold < 1:
		bucket = 1
	return bucket

def get_keywords(quote, bucket):
	'''
	Calls articles.go to get keywords from each query
	Adds keywords to list in dictionary for each quartile of probability
	'''
	keywords_list, dates = go(key, quote)
	if len(keywords_list) == 0:
		print ("No returned results")
	else:
		for each in dates:
			if each:
				DATES[bucket].append(each[:4])
		for word in keywords_list:
			print word
			regex = re.compile('\(.+?\)')
			word = regex.sub('', word)
			word = str(word)
			QUART_DICT[bucket].append(word)

def convert_dict_to_csv():
	'''
	Takes final dictionary and dumps each bucket key into a separate CSV filename
	'''

	for key in QUART_DICT.keys():
		key_string = str(key)
		# name = OUTPUT_DIRECTORY + "words/" + key_string + ".csv"
		name = "articles/" + key_string + ".csv"

		with open(name, 'w') as csvfile:
			w = csv.writer(csvfile)
			words = QUART_DICT[key]
			w.writerow(words)

	for key in DATES.keys():
		key_string = str(key)
		name = "articles/datesfor" + key_string + ".csv"
		# name = OUTPUT_DIRECTORY + "dates/datesfor_" + key_string + ".csv"

		with open(name, 'w') as csvfile:
			w = csv.writer(csvfile)
			words = DATES[key]
			w.writerow(words)

if __name__ == '__main__':
	# filename = 'training.txt'
	filename= '/home/csking1/buddhism/Finding/Output/file_14_b.txt'

	# filename = 'new_csv.csv'
	# key = '&api-key=01f2b56924bc493e87d25177ef24a697'
main(filename)
