from bs4 import BeautifulSoup
import requests
import re
from sys import exit
import sys

def checker():
 pageURL ='http://chico.craigslist.org/search/ela'
 params =dict(query=sys.argv[1])
 response= requests.get(pageURL, params=params)
 print (response.url)
 soup = BeautifulSoup(response.text, 'html.parser')
 if sys.argv[1].lower() in str(soup.findAll('a',{'class':'result-title'})).lower():
    for listing in soup.find_all('p'):
        #counter1 += 1
        if listing.find('a', class_='result-title') != None:
            a = listing.find('a', class_='result-title')
#        b = listing.find('span', class_='result-price')
            c = listing.find('span', class_='result-hood')
#        d = listing.find('time',class_='result-date')
            if sys.argv[1].lower() in str(listing.find('a', class_='result-title')).lower() and sys.argv[2].lower() in str(listing.find('span', class_='result-hood')).lower():
                print("title = ",a.text, "location = ", c.text)
 else:
    print('not on page')

def startup():
    Item = sys.argv[1]
    City = sys.argv[2]

startup()
checker()
if int(sys.argv[3]) > 120:
     print ( 'newpage')
     pageURL ='http://chico.craigslist.org/search/ela'
     params = dict(s=sys.argv[3],query=sys.argv[1])
     response= requests.get(pageURL, params=params)
     print (response.url)
     soup = BeautifulSoup(response.text, 'html.parser')
     if sys.argv[1].lower() in str(soup.findAll('a',{'class':'result-title'})).lower():
        for listing in soup.find_all('p'):
            #counter1 += 1
            if listing.find('a', class_='result-title') != None:
                a = listing.find('a', class_='result-title')
    #        b = listing.find('span', class_='result-price')
                c = listing.find('span', class_='result-hood')
    #        d = listing.find('time',class_='result-date')
                if sys.argv[1].lower() in str(listing.find('a', class_='result-title')).lower() and sys.argv[2].lower() in str(listing.find('span', class_='result-hood')).lower():
                    print("title = ",a.text, "location = ", c.text)
