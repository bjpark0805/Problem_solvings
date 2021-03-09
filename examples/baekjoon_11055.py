import sys
from functools import lru_cache
sys.setrecursionlimit(10**6)
def input(_type=str):
	return _type(sys.stdin.readline().strip())

A = []

@lru_cache(None)
def recbiggestSubstr(i, prev):
	if i == len(A):
		return 0
	ans = recbiggestSubstr(i+1, prev)
	if A[i] > prev:
		ans = max(ans, A[i] + recbiggestSubstr(i+1, A[i]))
	return ans

def main():
	global A
	N = input(int)
	A = list(map(int, input().split()))
	print(recbiggestSubstr(0, 0))

main()