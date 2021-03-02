import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

cache = {1: 0, 2: 1}
def recCal(x):
	global cache
	if x in cache:
		return cache[x]
	m = 1 + min(recCal(x//3) + x%3, recCal(x//2) + x%2)
	cache[x] = m
	return m

def main():
	N = input(int)
	print(recCal(N))

main()

