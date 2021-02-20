def main():
	N, S = list(map(int, input().split()))
	seq = list(map(int, input().split()))
	i, j, sum_ = 0, 0, seq[0]
	ans = N+1
	while j < N:
		if sum_ < S:
			j += 1
			sum_ += seq[j] if j < N else 0
		else:
			ans = min(ans, j-i+1)
			sum_ -= seq[i]
			i += 1
	ans = 0 if ans == N+1 else ans
	print(ans)

if __name__ == '__main__':
	main()

