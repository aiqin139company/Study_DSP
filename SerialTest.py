import sys
import serial
import csv
import math
import struct
import time

def ser_write(data):
	writeData = data
	writeBuff = struct.pack('l', writeData)
	ser.write(writeBuff)
	
if len(sys.argv) != 2:
	print 'Invalid usage, format is: ' 
	print '\t %s "COMx"' % (sys.argv[0])
else:
	portName = sys.argv[1]
	
ser = serial.Serial()
ser.baudrate = 230400
ser.port = portName
ser.timeout = 10.0

print "Opening serial port: " + portName
ser.open()
MAX_SAMPLES = 40000
TEST_MAX = 5
motorSpeed = 15

if not ser.is_open:
	print "Count not open serial port '%s'" % portName
else:	
	times = 0
	samples = 0
	dataList = []
	timedOut = False;
	
	ser_write(0xAAAA)
	print "setting the motor speed!"
	ser_write(motorSpeed)
	
	ser_write(0xA0A0)
	print "starting the motor!"
	
	sciData = ser.read(4)
	
	if 0 == ser.inWaiting():
		print "the encoder test ok!"
	else :
		dat = (struct.unpack(">l", sciData))[0]
		if 0xFFFF == dat :
			print "the encoder test faild!"
	
	ser_write(0x0A0A)	
	print "starting the motor!"
	