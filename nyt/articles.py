
import csv
import requests
import json
# KEY = 'api-key=01f2b56924bc493e87d25177ef24a697'

url = 'https://api.nytimes.com/svc/search/v2/articlesearch.json?'

def make_connection(key, query):
    '''
    Takes an NYT api key and string query and connects with New York Times API
    '''
    request_string = url + key + '&q='+ query
    req = requests.get(request_string)
    return json.loads(req.text)

def parse_to_csv(json_dict):
    '''
    Takes dictionary formerly known as a json and parses out 
    summary text, url, date, and keywords
    '''
    articles = json_dict["response"]["docs"]
    for each in articles:
        print ("--------------------------------------------------------------")    
        summary = each["summary"]
        url= each["web_url"]
        date = each["pub_date"]
        keywords_l = []
        keywords = each["keywords"]
        for each in keywords:
            word = each["value"]
            print (word)

def go(key, query):
    '''
    Wrapper function that takes api key, string query
    Calls make_connection and received an article dictionary
    Calls parse_to_csv to grab important information out of each inner dictionary
    '''
    json_dict = make_connection(key, query)
    parse_to_csv(json_dict)


if __name__ == '__main__' :

    key = '&api-key=01f2b56924bc493e87d25177ef24a697'
    query = 'Donald Trump'

go(key, query)    






