import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, M = map(int, input().split())
	expenses = [input(int) for _ in range(N)]
	m = max(expenses)
	minv, maxv = m, m * (N//M + 1)
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		current, cnt = midv, 1
		for e in expenses:
			if e <= current:
				current -= e
			else:
				current = midv - e
				cnt += 1
		if cnt <= M:
			maxv = midv
		else:
			minv = midv + 1

	current, cnt = minv, 1
	for e in expenses:
		if e <= current:
			current -= e
		else:
			current = minv - e
			cnt += 1 
	if cnt <= M:
		maxv = minv
	print(maxv)

main()