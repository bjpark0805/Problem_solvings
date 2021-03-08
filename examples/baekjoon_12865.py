import sys
from functools import lru_cache
sys.setrecursionlimit(10**6)

def input(_type=str):
	return _type(sys.stdin.readline().strip())

"""
recursive method

items = [[0,0]]

@lru_cache(None)
def recKnapsack(n, k):
	if k == 0 or n == 0:
		return 0

	global items 
	tmp = 0
	if items[n][0] <= k:
		tmp = recKnapsack(n-1, k-items[n][0]) + items[n][1]	
	return max(recKnapsack(n-1, k), tmp)
"""

def main():
	# global items
	items = []
	N, K = map(int, input().split())
	for i in range(N):
		items.append(list(map(int, input().split())))
	items.sort()
	values = [0] * (K+1)
	# item: weight, value
	for i in range(N):
		tmp = values[:] # python list copy by value
		for j in range(items[i][0], K+1):
			tmp[j] = max(values[j], values[j-items[i][0]]+items[i][1])
		values = tmp
		print(values)
	print(values[K])
main()
