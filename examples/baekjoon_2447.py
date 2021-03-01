import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	board = []
	N = input(int)
	for _ in range(N):
		board.append([" "]*N)
	def recBoard(r1, c1, N):
		if N > 3:
			for i in range(3):
				for j in range(3):
					if i == 1 and j == 1:
						continue
					recBoard(r1+i*N//3, c1+j*N//3, N//3)
		else:
			for i in range(3):
				for j in range(3):
					if i == 1 and j == 1:
						continue
					board[r1+i][c1+j] = "*"
					
	recBoard(0, 0, N)
	for i in range(N):
		print("".join(board[i]))

main()