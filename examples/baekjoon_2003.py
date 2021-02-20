def main():
	n, m = list(map(int, input().split()))
	A = list(map(int, input().split()))
	s = 0
	p = 0
	q = 0
	ans = 0
	while q < n:
		s += A[q]
		if s == m:
			ans += 1
			q += 1
		elif s < m:
			q += 1
		else:
			s -= A[q]
			s -= A[p]
			p += 1
	print(ans)


if __name__ == '__main__':
	main()