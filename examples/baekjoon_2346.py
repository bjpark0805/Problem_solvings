import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	balloon, ans = [i for i in range(1, N+1)], []
	paper = list(map(int, input().split()))
	curr = 0
	while balloon:
		n, p = len(balloon), paper[curr]
		ans.append(balloon[curr])
		del balloon[curr]
		del paper[curr]
		if n != 1:
			if p > 0:
				p -= 1
			curr = (curr + p)%(n-1)

	for a in ans[:-1]:
		print(a, end=" ")
	print(ans[-1])

main()