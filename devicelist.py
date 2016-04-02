#!/usr/bin/python 

import glob
import serial

def get_serial():
	ports = glob.glob('/dev/tty[A-Za-z]*')

	res = []
	for port in ports:
		try:
			s = serial.Serial(port)
			s.close()
			res.append(port)
		except:
			pass

	return res 

if __name__ == "__main__":
	print get_serial()
