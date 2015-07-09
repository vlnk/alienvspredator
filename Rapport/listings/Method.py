#!/usr/local/bin/python3.3
# -*-coding:utf-8-*
import re

function_key_words = [
	"inline", 
	"virtual",
	"operator"
]

class Method:
	"""docstring for Method"""

	def __init__(self, line, class_name):
		
		self.ret = ''
		self.name = ''
		self.parameters = []

		if type(line) is not dict:
			raise TypeError()
		elif line:

			#method name
			if re.search(r'\~', line["n"]):
				self.name = 'destructor'
			elif re.search(r'%s'%"operator", line["r"]):
				self.name = "operator " + line["n"]
			elif re.search(r'%s'%class_name, line["p"]):
				self.name = 'copy'
			elif (line["n"] == class_name):
				self.name = 'constructor'
			else:
				self.name = line["n"]

			#return type
			self.ret = line["r"]
			for key_word in function_key_words:
				self.ret = re.sub(r".?%s.?" % key_word, '', self.ret)

			#parameters
			params = line["p"].split(', ')

			for param in params:
				if param:
					self.parameters.append(param)

	def __getattr__(self, name):
		return self.name

	def __getattr__(self, ret):
		return self.ret

	def __getattr__(self, parameters):
		return self.parameters

	def __str__(self):
		#Name
		string = "method name : {}\n".format(self.name)

		#Return
		if self.ret:
			string = string + "return type : {}\n".format(self.ret)
		else:
			string = string + "this method returns nothing\n"

		#Parameters
		if self.parameters:
			string = string + "parameters : "
			string = string + "{}\n".format(self.parameters)
		else:
			string = string + "this method has no parameters\n"

		#other stuffs
		if (self.have_a_pass_by_reference()):
			string = string + "this method has pass by reference\n"

		if (self.have_a_pass_by_pointer()):
			string = string + "this method has pass by pointer\n"

		if (self.have_boolean()):
			string = string + "this method returns boolean\n"

		if (self.have_integer()):
			string = string + "this method returns integer\n"

		"""
		if (not self.have_a_pass_by_reference() and
			not self.have_a_pass_by_pointer() and
			not self.have_boolean() and
			not self.have_integer()):
			string = string + "this method don't "\
			"have neither pass by references "\
			"nor reference by pointers and "\
			"doesn't return neither boolean nor integer"
		"""

		return string

	def have_a_pass_by_reference(self):
		r = False

		if re.search(r'&', self.ret):
			r = True

		return r

	def have_a_pass_by_pointer(self):
		r = False

		if re.search(r'\*', self.ret):
			r = True

		return r

	def have_boolean(self):
		r = False

		if re.search(r'bool', self.ret.lower()):
			r = True

		return r

	def have_integer(self):
		r = False

		if re.search(r'int', self.ret.lower()):
			r = True

		return r		


