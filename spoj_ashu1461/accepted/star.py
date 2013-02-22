n=int(raw_input())
if n >1:
	print (n/2)*' '+'*'
for i in range(0,n/2-1):
	print (n/2-1-i)*' '+'*'+i*' '+'*'+i*' '+'*'
print n*'*'
for i in range(0,n/2-1):
	print (i+1)*' '+'*'+(n/2-2-i)*' '+'*'+(n/2-2-i)*' '+'*'
if n>1:
	print (n/2)*' '+'*'
