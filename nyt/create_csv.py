
import csv

def convert_dict_to_csv():
	with open("test.csv", 'w', newline="") as csvfile:
       	w = csv.writer(csvfile, delimiter=',')
    	w.writerow(["Date", "Summary", "Keywords", "Url" ])