
from articles import go
import csv
import chardet

key = '&api-key=01f2b56924bc493e87d25177ef24a697'
QUART_DICT = {.25:[],.5:[],.75:[], 1:[]}
NO_RETURN = 0

def main(filename):
	'''
	Takes in output csv from Gutenberg scraping/Naive Bayes Algorithm 
	on how "Buddhist" each quote is. 
	Note: Chardet is used to circumvent text encoding ISO-8859-2
	'''
	with open (filename, 'rb') as f:
		result = chardet.detect(f.read())
	encoding = result['encoding']

	with open(filename, 'r', encoding = encoding) as csvfile:
		reader = csv.reader(csvfile)
		for line in reader:
			quote = line[0]
			threshold = float(line[1])
			bucket = get_bucket(threshold)
			get_keywords(quote, bucket)

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

def create_query():
	'''
	Measures if string is within limits and parses down if not.
	Grabs probability threshold measure from NLP on how "Buddhist" a quote is. 
	'''
	pass
	csv_file = "articles/" + query.strip() + ".csv"


def get_keywords(quote, bucket):
	'''
	Calls articles.go to get keywords from each query
	Adds keywords to list in dictionary for each quartile of probability
	'''

	keywords_list = go(key, quote)
	if len(keywords_list) == 0:
		print ("No returned results")
	else:
		for word in keywords_list:
			QUART_DICT[bucket].append(word)
	print (QUART_DICT)

def convert_dict_to_csv():
	pass


if __name__ == '__main__':
	filename = 'for_nyt.csv'
	# key = '&api-key=01f2b56924bc493e87d25177ef24a697'
	query = "If one speaks or acts with a pure mind, happiness follows like a shadow that never departs."
  
main(filename)
