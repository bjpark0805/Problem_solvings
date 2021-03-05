import sys
import math
from collections import defaultdict
def input(_type = str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	squares = []
	i = 1
	squares = [i**2 for i in range(1, int(math.sqrt(N))+1)]
	cnt = defaultdict(int)
	cnt[1] = 1

	for i in range(2, N+1):
		if int(math.sqrt(i))**2 == i:
			cnt[i] = 1
			continue
		num = i
		for sq in squares:
			if sq > i:
				break
			num = min(cnt[i-sq], num)
		cnt[i] = num+1
	print(cnt[N])

main()