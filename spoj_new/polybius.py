d = int(raw_input())
for i in xrange(0,d):
	y = raw_input()
	for j in y[0:len(y)-1] :
		if(j!=' '):
 			print x[ord(j)-65],
	print x[ord(y[len(y)-1])-65]
exit(0)


