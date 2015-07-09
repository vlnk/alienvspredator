#!/usr/local/bin/python3.3
# -*-coding:utf-8-*
import argparse
from functions import *

if __name__ == "__main__":

	parser = argparse.ArgumentParser(
		description='Parse some c++ header files',
		prog='HeaderParser')
	parser.add_argument('-f', metavar='file', nargs='+')
	parser.add_argument('-d', metavar='directory', nargs='+')
	args = parser.parse_args()

	if (not args.d and not args.f):
		parser.print_help()

	if args.f:
		treatFile(args.f)

	if args.d:
		treatDir(args.d)