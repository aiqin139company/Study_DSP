import sys
import serial
import csv
import math
import struct

MAX_SAMPLES = 10000

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

motorSpeed = 14

if not ser.is_open:
	print "Count not open serial port '%s'" % portName
else:
	samples = 0
	dataList = [];
	timedOut = False;
		
	writeData = 0xAAAA
	writeBuff = struct.pack('l', writeData)
	ser.write(writeBuff)
	print "setting the motor speed!"
	
	writeData = motorSpeed
	writeBuff = struct.pack('l', writeData)
	ser.write(writeBuff)
		
	writeData = 0xA0A0
	writeBuff = struct.pack('l', writeData)
	ser.write(writeBuff)
	print "starting the motor!"
	
	while not timedOut and (samples < MAX_SAMPLES):
		
		sciData = ser.read(4)
		if len(sciData) <> 4:
			timedOut = True
		else:
			samples += 1
			dat = (struct.unpack(">l", sciData))[0]
			dat /= 60.0
			print "count%d: %f us" % ( samples, dat)
			dataList.append ( [dat] )
		
	writeData = 0x0A0A
	writeBuff = struct.pack('l', writeData)
	ser.write(writeBuff)
	print "stopping the motor!"
		
	csvfile = open('result.csv','wb')
	csvwriter = csv.writer(csvfile)
	for dataPoint in dataList:
		if ( not math.isnan(dataPoint[0]) ):
			csvwriter.writerow( dataPoint )
		else:
			csvwriter.writerow( "NAN" )
	csvfile.close()
			
