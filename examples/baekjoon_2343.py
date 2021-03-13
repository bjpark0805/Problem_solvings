import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, M = map(int, input().split())
	lessons = list(map(int, input().split()))
	lessons_sum = []
	sums = 0
	for l in lessons:
		sums += l
		lessons_sum.append(sums)
	m = max(lessons)
	minv, maxv = m, m*(N//M + 1)
	while minv + 1 < maxv:
		midv = (minv+maxv)//2
		prev, cnt = 0, 1
		for i in range(N):
			if lessons_sum[i] - prev > midv:
				prev, cnt = lessons_sum[i-1], cnt + 1
		if cnt <= M:
			maxv = midv
		else:
			minv = midv + 1

	prev, cnt = 0, 1
	for i in range(N):
		if lessons_sum[i] - prev > minv:
			prev, cnt = lessons_sum[i-1], cnt + 1
	if cnt <= M:
		maxv = minv
	print(maxv)

main()