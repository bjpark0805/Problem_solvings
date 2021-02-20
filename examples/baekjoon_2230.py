import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, M = list(map(int, input().split()))
	l = []
	for _ in range(N):
		l.append(input(int))
	l.sort()
	p, q = 0, 1
	min_dist = 2000000001
	while q < len(l):
		temp = l[q] - l[p]
		if temp == M:
			print(M)
			return
		elif temp > M:
			min_dist = min(min_dist, temp)
			p += 1
		else:
			q += 1
	
	print(min_dist)


if __name__ == '__main__':
	main()