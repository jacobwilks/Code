#!/usr/bin/python3.5
import pandas as pd
import numpy as np
from sys import exit
import sys
prompt = '> '
dicta={}
fields=['Year', 'Length', 'Title', 'Director']
fields1=['Year','Length','Title','budget', 'rating', 'Action', 'Animation', 'Comedy', 'Drama', 'Documentary', 'Romance', 'Short']


#Search a Movie
def choice1():
        print("name of movie u want to search")
        i = input(prompt)
        if i in dicta:
            print (dicta[i].values())
            print ("update something?")
            l=input(prompt)
            #l = l.lower()
            if 'yes' in l.lower():
                print("what field do u wanna update")
                print(dicta[i])
                n = input(prompt)
                print("with what?")
                m = input(prompt)
                dicta[i].update({n:m})
                print (dicta[i].values())
            else:
                print ( 'you didnt want to update anything so I sent you back here :)')
        else:
            print('not in dict')
#Print all Titles in merged and filtered dictionary
def printTitle():
        for key,value in dicta.items():
            print (key)
#Main Menu
def menu():
    while True:
        print("1 if u want to choose movie 2 if u want to see a list or 3 to quit")
        choice = input(prompt)
        if choice=='1':
            choice1()
        elif choice=='2':
            printTitle()
        else:
            exit(0)


a = pd.read_csv('films.csv',skipinitialspace=True, usecols=fields, encoding = "ISO-8859-1")
b = pd.read_csv('movies.csv',skipinitialspace=True, usecols=fields1, encoding = "ISO-8859-1")
df = pd.merge(a,b, on='Title')
df=df.dropna(subset=['budget'])
df = df.drop_duplicates(subset=['Title'])
dicta=df.set_index('Title').T.to_dict()

#Starts the Program
menu()
