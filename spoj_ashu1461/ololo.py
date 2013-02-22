a=[]
x=int(raw_input())
print x
for i in range(0,x):
	y=int(raw_input())
	if y not in a :
		a.append(y)
	else :
		a.remove(y)
print a[0]
