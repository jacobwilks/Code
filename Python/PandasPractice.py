import pandas as pd
import numpy as np
from sys import *
import sys
import argparse

file_name = 'NASA_access_log_Jul95'
command = sys.argv[1] #help,resources,requesters,errors,hourly

if command in "--help":
    print('--help brings you here silly')
    print('--requesters tells you how many times each ip requested a resource. Format = Count / IP')
    print('--resources counts how many times each resource has been requested. Format = Count / Name')
    print('--errors how many times resources that errored out were requested. Format= Count/Name')
    print('--hourly counts requests that come in each hour in military time. Format = Count / date/hour')
elif command in '--resources':
    file_name = 'NASA_access_log_Jul95'
    numCheck = sys.argv[4]
    if numCheck in '--number':
        numValue = int(sys.argv[5])
        location = sys.argv[6]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >=1]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        results = pd.value_counts(data[5].values,sort=True, ascending=False).nlargest(numValue)
        print(results)
    else:
        location = sys.argv[4]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >=1]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        results = pd.value_counts(data[5].values,sort=True, ascending=False).nlargest(10)
        print(results)
elif command in '--requesters':
    data = pd.read_csv('NASA_access_log_Jul95', skipinitialspace=True, error_bad_lines=False, warn_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
    numCheck = sys.argv[4]
    if numCheck in '--number':
        numValue = int(sys.argv[5])
        location = sys.argv[6]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >=1]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        ipResultSort = pd.value_counts(data[0].values,sort=True, ascending=False).nlargest(numValue)
        print(ipResultSort)
    else:
        location = sys.argv[4]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >=1]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        ipResultSort = pd.value_counts(data[0].values,sort=True, ascending=False).nlargest(10)
        print(ipResultSort)
elif command in '--errors':
    numCheck = sys.argv[4]
    if numCheck in '--number':
        numValue = int(sys.argv[5])
        location = sys.argv[6]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >= 400]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        errorCount = pd.value_counts(data[5].values,sort=True, ascending=False).nlargest(numValue)
        print(errorCount)
    else:
        location = sys.argv[4]
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        data = data[data[6] >= 400]
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        errorCount = pd.value_counts(data[5].values,sort=True, ascending=False).nlargest(10)
        print(errorCount)
elif command in '--hourly':
    numCheck = sys.argv[4]
    if numCheck in '--number':
        numValue = int(sys.argv[5])
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:15]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        result = pd.value_counts(data[3].values, sort=True, ascending=False).nlargest(numValue)
        print(result)
    else:
        data = pd.read_csv(file_name,skipinitialspace=True, error_bad_lines=False, sep=" ", header=None, encoding="ISO-8859-1")
        beg_day = '10'
        end_day = '20'
        data[3] = data[3].str[1:3]
        data = data[(data[3]>=beg_day) & (data[3]<=end_day)]
        result = pd.value_counts(data[3].values, sort=True, ascending=False).nlargest(10)
        print(result)
