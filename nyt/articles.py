
import csv
import requests
import json
import re


url = 'https://api.nytimes.com/svc/search/v2/articlesearch.json?'

def make_connection(key, query):
    '''
    Takes an NYT api key and string query and connects with New York Times API
    '''
    request_string = url + key + '&q='+ query
    req = requests.get(request_string)
    return json.loads(req.text)

        
def go(key, query):
    '''
    Wrapper function that takes api key, string query
    Calls make_connection and received an article dictionary
    Calls parse_to_csv to grab important information out of each inner dictionary
    '''
    keywords_list= []
    dates = []

    try:
        json_dict = make_connection(key, query)
        articles = json_dict["response"]["docs"]
        for each in articles:
            date = each["pub_date"]
            dates.append(date)
            keywords = each["keywords"]
            for each in keywords:
                keywords_list.append(each["value"])
       
    except:
        print("Connection Failed")

    return keywords_list, dates

    ##################Below code for storing results of query into CSVs##########

    # csv_file = "articles/" + query.strip() + ".csv"
    # with open(csv_file, 'w', newline="") as csvfile:
    #     w = csv.writer(csvfile, delimiter=',')
    #     w.writerow(["Date", "Summary", "Keywords", "Url" ])
    #     for i in range(10):
    #         try:
    #             json_dict = make_connection(key, query)
    #             articles = json_dict["response"]["docs"]
    #             for each in articles:
    #                 summary = each["lead_paragraph"]
    #                 url= each["web_url"]
    #                 date = each["pub_date"]
    #                 keywords_l = []
    #                 keywords = each["keywords"]
    #                 for each in keywords:
    #                     keywords_l.append(each["value"])
    #                 w.writerow([date, summary, keywords_l, url])


    #         except:
    #             print("Connection Failed")
