
from sys import exit
import os
from os import path
import glob
import os.path
prompt = '> '
num=0
x=0
def menu():
    print "Main Menu:"
    print "1. Create a File"
    print "2. Create a Directory"
    print "3. Remove a File/Directory"
    print "4. Display File system"
    print "5. Exit"
def choice1():
    print "Choice 1"
    print "Please enter a File name or quit (add .txt)"
    filename = raw_input(prompt)
    if filename == "quit":
        quit()
    print "Please enter a parent dir or quit:"
    parentdir = raw_input(prompt)
    if parentdir == "quit":
        quit()
    print "Created File: %s" %filename
    print "please enter size(1-Small, 2-Medium, 3-Large)"
    size = raw_input(prompt)
    if parentdir and filename:
            start_path = '/Users/jacobwilks/Desktop/CINS334/'
            final_path = os.path.join(start_path, parentdir)
            final_final_path= os.path.join(final_path, filename)
            open(final_final_path, 'w')
    elif filename:
        open(filename, "w")
        print "created file %s %s %s " % ( filename, parentdir, size)
    menu()
    choice()
def choice2():
    x=0
    print "Choice 2"
    print "Please enter Directory name or quit: "
    dirname= raw_input(prompt)
    if dirname == "quit":
        quit()
    print "Please enter a parent directory or quit: "
    parentdir = raw_input(prompt)
    if parentdir == "quit":
        quit()
    if parentdir:
        start_path = '/Users/jacobwilks/Desktop/CINS334/'
        final_path = os.path.join(start_path, parentdir)
        final_final_path=os.path.join(final_path, dirname)
        os.makedirs(final_final_path)
    else:
        os.makedirs(dirname)
    print "Created Directory: %s" %dirname
    menu()
    choice()
def choice3():
    printSystem()
    print "Please enter a File name or quit(or leave empty)"
    filename = raw_input(prompt)
    if filename == "quit":
        quit()
    print "Please enter a DIR name or quit(or leave empty)"
    dirname = raw_input(prompt)
    if dirname == "quit":
        quit()
    if dirname and filename:
        start_path = '/Users/jacobwilks/Desktop/CINS334/'
        final_path = os.path.join(start_path, dirname)
        final_final_path= os.path.join(final_path, filename)
        os.remove(final_final_path)
    if dirname and not filename:
        os.removedirs(dirname)
    if filename and not dirname:
        os.remove(filename)
    menu()
    choice()
def choice4():
    printSystem()
    menu()
    choice()
def quit():
    print "bye"
    exit(0)
def choice():
    choice=raw_input(prompt)
    if choice == "quit" or choice == "5" :
        quit()
    elif choice == "1":
        choice1()
    elif choice == "2":
        choice2()
    elif choice == "3":
        choice3()
    else:
        choice4()
def start():
    menu()
    choice()
def printSystem():
    root = "./"
    for root, subdirs, files in os.walk(root):
        if 'lab' not in root:
            for name in files:
                print os.path.join(root, name)
def permissions():
    x=0
    permissions=raw_input(prompt)
    if permissions == "quit":
        quit()
    if "r" in permissions:
        x=x+400
    if "w" in permissions:
        x=x+200
    if "x" in permissions:
        x=x+100
    else:
        print "no permissions entered"
        x=0

while True:
    start()
