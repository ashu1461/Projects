def function():
	x=raw_input()
	x=raw_input()
	plus=0
	machula=-1
	equal=0
	for i in range(0,len(x)):
		if x[i]=='+':
			plus=i
		elif x[i]=='=':
			equal=i
		elif x[i]=='m':
			machula=i
	ans=0
	if machula > equal :
		ans=int(x[0:plus-1])+int(x[plus+1:equal-1])
		print x[0:equal+2]+str(ans)
	elif machula < plus :
		ans=int(x[equal+2:])-int(x[plus+1:equal-1])
		print str(ans)+x[plus-1:]
	elif machula!=-1:
		ans=int(x[equal+2:])-int(x[0:plus-1])
		print x[0:plus+2]+str(ans)+x[equal-1:]
	return 0;
y=int(raw_input())
for z in range(0,y):
	function()

