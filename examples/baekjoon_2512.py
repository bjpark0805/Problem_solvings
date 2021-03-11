import sys
def input(_type = str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	request = list(map(int, input().split()))
	M = input(int)
	minv, maxv = 0, max(request)
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		midsum = sum([v if v <= midv else midv for v in request]) 
		if midsum > M:
			maxv = midv - 1
		else:
			minv = midv
	if sum([v if v <= maxv else maxv for v in request]) <= M:
		minv = maxv
	print(minv)

main()