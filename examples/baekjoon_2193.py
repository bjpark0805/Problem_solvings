import sys
from functools import lru_cache
def input(_type=str):
	return _type(sys.stdin.readline().strip())
"""
Top down
p1(n): now 1, length n
-> p1(n) = p2(n-1) 

p2(n): now 0, length n
-> p2(n) = p2(n-1) + p1(n-1)

"""
@lru_cache(None)
def Pinary1(x):
	if x == 1:
		return 1
	return Pinary2(x-1)

@lru_cache(None)
def Pinary2(x):
	if x == 1:
		return 1
	return Pinary1(x-1) + Pinary2(x-1)

def iterPinary(x):
	a, b, i = 1, 1, 2
	while i < x:
		a, b, i = b, a + b, i + 1
	return b

def main():
	N = input(int)
	# print(Pinary1(N))
	print(iterPinary(N))

main()



