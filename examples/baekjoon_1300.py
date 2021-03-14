import sys
import math
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, k = input(int), input(int)
	minv, maxv = int(math.sqrt(k)), k
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		limit, cnt, last = min(N, midv), 0, 0
		for i in range(1, limit + 1):
			cnt += min(limit, midv // i) 
			last = max(last, min(limit, midv // i) * i)
		if cnt < k:
			minv = midv + 1
		else:
			maxv = last

	if minv < maxv:
		limit, cnt = min(N, minv), 0
		for i in range(1, limit + 1):
			cnt += min(limit, minv // i)
		if cnt >= k:
			maxv = minv
	print(maxv)

main()
