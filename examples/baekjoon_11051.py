import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, K = map(int, input().split())
	if N==K:
		print(1)
		return
	elif N < K:
		print(0)
		return
	dp = [[1] * (K+1) for _ in range(N+1)]
	for n in range(2, N+1):
		for k in range(1, min(K+1,n)):
			dp[n][k] = (dp[n-1][k-1] + dp[n-1][k])%10007

	print(dp[N][K])

main()
