    
url = 'https://api.nytimes.com/svc/search/v2/articlesearch.json?'
key = '&api-key=7e90712233444f859a2b6bfe175ed4c1'
def go():
    try:
        json_dict = make_connection(key, "Obama")
        articles = json_dict["response"]["docs"]
        for each in articles:
            date = each["pub_date"]
            dates.append(date)
            keywords = each["keywords"]
            for each in keywords:
                print (each)
                keywords_list.append(each["value"])
    except:
        print("Connection Failed")

go()