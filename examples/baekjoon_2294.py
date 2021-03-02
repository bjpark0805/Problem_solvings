import sys
sys.setrecursionlimit(10**6)
from functools import lru_cache
def input(_type=str):
	return _type(sys.stdin.readline().strip())

coins = []

@lru_cache(None)
def recCnt(k):
	"""
	Recursive solution
	
	recCnt(k) : minimum number of coins for money k
	recCnt(k) = 
		for each coin of coins
			min(recCnt(k-coin))  

	"""
	if k == 0:
		return 0
	ans = 10001
	for c in coins:
		if k - c >= 0:
			ans = min(ans, recCnt(k-c))
	return ans + 1

def main():
	global coins
	n, k = map(int, input().split())
	temp = set()
	for i in range(n):
		temp.add(input(int))
	coins = sorted(list(temp), reverse= True)
	"""
	iterative ways: similar to recursive way
	
	cache[k] = minimum number of coins for money k
	cache[k] = 
		for each coin of coins
			min(cache[k-coin])  
			
	"""
	cache = [10001] * (k+1)
	cache[0] = 0
	for i in range(1, k+1):
		cnt = 10001
		for c in coins:
			if i - c >= 0:
				cnt = min(cnt, cache[i-c]+1)
		cache[i] = cnt
	ans = cache[k]
	if ans > 10000:
		ans = -1
	print(ans)

main()