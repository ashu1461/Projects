def function(a):
	y=''
	i=0
	while i < len(a):
		if a[i]!='_':

			y=y+a[i]
			if ord(a[i-1])>122 or ord(a[i-1]) <97:
				print 'Error!'
				exit()
		else:
			y=y+chr(ord(a[i+1])-32)
			i=i+1
		i=i+1
	print y		
def function2(a):
	y=''
	for i in range(0,len(a)):
		if ord(a[i])<95:
				y=y+'_'+chr(ord(a[i])+32)
		else:
				y=y+a[i]
	print y
a=str(raw_input())
if a[0]== '_' or a[len(a)-1]== '_' or ord(a[0]) < 95:
	print 'Error!'
	exit()
flag=0
flag1=0
for i in range(0,len(a)):
	if a[i]=='_' and flag==0:
		flag=1
	elif ord(a[i]) < 95 and flag1==0:
		flag1=1
	if flag==1 and flag1==1:
		print 'Error!'
		exit()
if flag==1:
	function(a)
else:
	function2(a)
