import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N,M = list(map(int, input().split()))
	lines = [['B','W','B','W','B','W','B','W'], ['W','B','W','B','W','B','W','B']]
	first = []
	board = []
	for i in range(8):
		first.append(lines[i%2])
	for _ in range(N):
		board.append(list(input()))
	ans = 64
	for i in range(N-7):
		for j in range(M-7):
			n1 = 0
			for k in range(8):
				for l in range(8):
					n1 += 1 if board[i+k][j+l] != first[k][l] else 0
			ans = min(n1, 64-n1, ans)
	print(ans)

main()