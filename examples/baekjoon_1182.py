import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

ans = 0
def main():
	N, S = list(map(int, input().split()))
	nums = list(map(int, input().split()))
	global ans
	def partial_seq(i, s):
		global ans
		if i == N:
			if s == S:
				ans += 1
			return
		partial_seq(i+1, s)
		partial_seq(i+1, s+nums[i])
	partial_seq(0, 0)
	ans -= 1 if S == 0 else 0
	print(ans)

main()