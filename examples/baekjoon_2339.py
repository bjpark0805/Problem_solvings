import sys
from functools import lru_cache 
def input(_type=str):
	return _type(sys.stdin.readline().strip())

board = []

@lru_cache(None)
def recCut(r1, r2, c1, c2, direct):
	"""
	horizontal: direct = False 
	vertical : direct = True
	"""
	global board
	board_ = [board[i][c1:c2] for i in range(r1, r2)]
	if (r2 <= r1 + 2 and not direct) or (c2 <= c1 + 2 and direct):
		one,two = False, False
		for i in range(len(board_)):
			if 1 in board_[i]:
				one = True
			if 2 in board_[i]:
				two = True
		return 1 if (not one and two) else 0

	cnt = 0
	exist_one, num_two = False, 0
	if direct:
		board_ = list(zip(*board_))
		for i in range(len(board_)): 
			if 1 in board_[i]:
				exist_one = True
				if 2 not in board_[i] and i != 0 and i != len(board_)-1:
					cnt += recCut(r1, r2, c1, c1+i, False) * recCut(r1, r2, c1+i+1, c2, False)
			if 2 in board_[i]:
				num_two += 1
		if not exist_one:
			return 1 if num_two == 1 else 0

	else:
		for i in range(len(board_)):
			if 1 in board_[i]:
				exist_one = True
				if 2 not in board_[i] and i != 0 and i != len(board_)-1:
					cnt += recCut(r1, r1+i, c1, c2, True) * recCut(r1+i+1, r2, c1, c2, True)
			if 2 in board_[i]:
				num_two += 1
		if not exist_one:
			return 1 if num_two == 1 else 0
	return cnt

def main():
	global board
	N = input(int)
	for _ in range(N):
		board.append(list(map(int, input().split())))
	cnt = recCut(0, N, 0, N, False)
	if N > 2:
		cnt += recCut(0, N, 0, N, True)
	if cnt == 0:
		cnt = -1
	print(cnt)

main()