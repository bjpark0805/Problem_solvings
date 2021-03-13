import sys
def input(_type = str):
	return _type(sys.stdin.readline().strip())

def main():
	N, C = map(int, input().split())
	X = [input(int) for _ in range(N)]
	X.sort()
	X_diff = [X[i] - X[i-1] for i in range(1, len(X))]
	minv, maxv = min(X_diff), X[-1]-X[0]
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		cnt, prev, diff = 1, X[0], maxv 
		for x in X[1:]:
			if x - prev >= midv:
				diff, prev, cnt = min(diff, x - prev), x, cnt + 1

		if cnt >= C:
			minv = diff
		else:
			maxv = diff - 1

	cnt, prev, diff = 1, X[0], X[-1]-X[0]
	for x in X[1:]:
		if x - prev >= maxv:
			diff, prev, cnt = min(diff, x-prev), x, cnt + 1
	if cnt >= C:
		minv = maxv
	print(minv)

main()
