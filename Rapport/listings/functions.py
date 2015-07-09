#!/usr/local/bin/python3.3
# -*-coding:utf-8-*

import re
import os
from Method import *
from Class import *

def argParser(string):
	"""This function parses arguments with regular expression""" 
	return re.search(r'\w\.(hpp|h)$', string)

def getClassName(string):
	"""This function get a class name from a string"""
	tmp = re.search(r'^class\s(\w*)\s', string)

	if (tmp is not None):
		return tmp.group(1)

def parseLine(line):
	dic = {}
	if (not re.search(r'^\s*//', line) and not re.search(r'\w*:\s*$', line) and
		not re.search(r'^#', line) and not re.search('^\s$', line) and
		not re.search(r'^[{|}]', line)):

		line.replace('\n','')

		parsed_line = re.search(r'^\s*(?P<r>[\w&\*:\s]*)\s(?P<n>.*)\s*\((?P<p>.*)\)', line)

		if parsed_line:
			dic["n"] = parsed_line.group('n')
			dic["p"] = parsed_line.group('p')
			dic["r"] = parsed_line.group('r')
			return dic

def readHeader(header):
		file = open(header, "r")
		parsed_line = {}
		find_class = False
		
		for line in file.readlines():

			class_name = getClassName(line)
			if class_name:
				main_class = Class(header, class_name)
				find_class = True

			dic_method = parseLine(line)
			if (dic_method and find_class):
				main_class.additem(Method(dic_method, main_class.name))

		if find_class:
			print('*' + '-'*50 + '*')
			main_class.display()

		file.close()

def treatFile(list_file):
	for f in list_file:
		if argParser(f):
			readHeader(f)

def treatDir(list_dir):
	for path in list_dir:
		abr = os.walk(path)

		for d in abr:
			for f in d[2]:
				print(f)
				if argParser(f):
					readHeader(d[0] + '/' + f)



