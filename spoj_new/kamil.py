for i in range(10):
	s=raw_input()
	x = sum(s.count(i) for i in 'DLFT')
	print 2**x
