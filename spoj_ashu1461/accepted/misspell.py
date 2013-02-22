y=int(raw_input())
for z in range(0,y):
	x=raw_input()
	i=int(x[0])
	x=x[2:]
	print str(z+1)+' '+x[0:i-1]+x[i:]
