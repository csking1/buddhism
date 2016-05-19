
import csv
import requests
import json

api_key = 'api_key=01f2b56924bc493e87d25177ef24a697'

def make_connection():
    url = "https://api.nytimes.com/svc/topstories/v2/home.json?"
    url = url + api_key
    req = requests.get(url)
    j = json.loads(req.text)
    print (j)

make_connection()