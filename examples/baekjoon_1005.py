import sys
from functools import lru_cache
def input(_type=str):
	return _type(sys.stdin.readline().strip())
 
def main():
	T = input(int)
	for _ in range(T):
		N, K = map(int, input().split())
		time = list(map(int, input().split()))
		prev_task = [[] for _ in range(N+1)]
		for _ in range(K):
			X, Y = map(int, input().split())
			prev_task[Y].append(X)
		W = input(int)

		@lru_cache(None)
		def recACM(n):
			if not prev_task[n]:
				return time[n-1]
			return max([recACM(x) for x in prev_task[n]]) + time[n-1]

		print(recACM(W))

main()



