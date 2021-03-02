import sys
from functools import lru_cache
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	T = input(int)
	for _ in range(T):
		n = input(int)
		arr, score = [], []
		arr.append(list(map(int, input().split())))
		arr.append(list(map(int, input().split())))
		arr = list(map(list, zip(*arr)))
		topTrue, bottomTrue, bothFalse = 0, 0, 0
		for s1, s2 in arr:
			n_topTrue = s1 + max(bottomTrue, bothFalse)
			n_bottomTrue = s2 + max(topTrue, bothFalse)
			n_bothFalse = max(topTrue,bottomTrue)
			topTrue, bottomTrue, bothFalse = n_topTrue, n_bottomTrue, n_bothFalse
		print(max(topTrue, bottomTrue, bothFalse))
	
main()