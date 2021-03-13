import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, K, D = map(int, input().split())
	rules = [tuple(map(int, input().split())) for _ in range(K)]
	minv, maxv = min([r[0] for r in rules]), max([r[1] for r in rules])
	while minv + 1 < maxv:
		midv = (minv + maxv)//2 
		cnt, max_in = 0, 0
		for A, B, C in rules:
			if midv < A:
				continue
			n = (min(midv, B)-A)//C
			max_in = max(A + n * C, max_in)
			cnt += n + 1
		# print(minv, midv, maxv, max_in, cnt)
		if cnt >= D:
			maxv = max_in
		else:
			minv = midv + 1

	if minv < maxv:
		cnt, max_in = 0, 0
		for A, B, C in rules:
			if minv < A:
				continue
			max_in = max(A + (min(minv, B)-A)//C * C, max_in)
			cnt += (min(minv, B) - A)//C + 1
		if cnt >= D:
			maxv = max_in
	print(maxv)

main()

# 10 20 30 40 50
#       30       60   90
#    20     45      70
#                   70  95