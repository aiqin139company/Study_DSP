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
	
def ser_read():
	sciData = ser.read(4)
	dat = (struct.unpack(">l", sciData))[0]
	return dat

if len(sys.argv) != 2:
	print 'Invalid usage, format is: ' 
	print '\t %s "COMx"' % (sys.argv[0])
else:
	portName = sys.argv[1]
	
ser = serial.Serial()
ser.baudrate = 230400
ser.port = portName
ser.timeout = 5.0

print "Opening serial port: " + portName
ser.open()

TEST_MAX = 5
motorSpeed = 15

if not ser.is_open:
	print "Count not open serial port '%s'" % portName
else:	
	times = 0
	dataList = []
	
	ser_write(0xAAAA)
	print "setting the motor speed!"
	ser_write(motorSpeed)
	
	#sample TEST_MAX times
	while times < TEST_MAX:
		times += 1
		
		ser_write(0xA0A0)
		print "starting the motor!"
		
		time.sleep(6)
		
		ser_write(0x0A0A)
		print "stopping the motor!"
		
		dat = ser_read()
		dat /= 60.0
		print "time%d : %f us" % (times,dat)
		
		dataList.append (dat)
		time.sleep(2)

	limit_H = dataList[0]/1.0 + dataList[0]/1.0 * 0.04
	limit_L = dataList[0]/1.0 - dataList[0]/1.0 * 0.04
	ok = 0
	times = 0
	while times < TEST_MAX - 1:
		times += 1
		if limit_H > dataList[times] and limit_L < dataList[times] :
			ok += 1
	
	print "ok : %d times " % (ok)
	if ok == 4:
		print "the encoder test ok!"
	else :
		print "the encoder test faild!"
