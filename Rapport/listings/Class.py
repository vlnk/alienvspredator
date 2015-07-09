#!/usr/local/bin/python3.3
# -*-coding:utf-8-*

class Class:
	"""docstring for Class"""

	def __init__(self, header_name, class_name):
		self.header = header_name
		self.name = class_name
		self.methods = []

	def __getattr__(self, header):
		return self.header

	def __getattr__(self, name):
		return self.name

	def __getattr__(self, methods):
		return self.methods

	def __getitem__(self, index):
		return self.methods[index]

	def __setitem__(self, index, value):
		self.methods[index] = value

	def additem(self, value):
		self.methods.append(value)

	def __len__(self):
		return len(methods)

	def __str__(self):
		string = "HEADER FILE : {}\n".format(self.header)
		string = string + "CLASS NAME : {}\n".format(self.name)

		return string

	def display(self):
		print(self)

		for method in self.methods:
			print(method)


