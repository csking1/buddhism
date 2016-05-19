
import csv
import requests
import json

KEY = 'api-key=01f2b56924bc493e87d25177ef24a697'

def make_connection():
	url = "https://api.nytimes.com/svc/topstories/v2/home.json?"
    url = url + KEY 
    print (url)
    req = requests.get(url)
    j_dict = json.loads(req.text)
    print (j_dict)
    return j_dict

def go():
	j_dict = make_connection()



if __name__ == '__main__' :

go()    







# url = "https://api.nytimes.com/svc/topstories/v2/home.json?"
# url = 'https://api.nytimes.com/svc/search/v2/articlesearch.json?'

##########################333
##code for cleaning
#why isn't this working? 
# def get_api_key(file): 
# 	with open(file, 'r') as f:
# 		key = f.read().strip("\n")
# 		print (key)
# 		return key