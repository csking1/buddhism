
import csv
import requests
import json


KEY = 'api-key=01f2b56924bc493e87d25177ef24a697'
url = 'https://api.nytimes.com/svc/search/v2/articlesearch.json?'
q = 'query = Buddhism'
url = url + &api-key
print (url)
req = requests.get(url)
j_dict = json.loads(req.text)
print (j_dict)
  