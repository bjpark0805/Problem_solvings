import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, M = map(int, input().split())
	idxs = list(map(int, input().split()))
	que = [i for i in range(1, N+1)]
	curr, ans = 0, 0
	for idx in idxs:
		n = len(que)
		for j in range(curr, curr+n):
			if que[j%n] == idx:
				ans += min(abs(j-curr), curr+len(que)-j)
				del que[j%n]
				if n != 1:
					curr = (j%n)%(n-1)
				break

	print(ans)

main()