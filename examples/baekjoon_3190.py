import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

class Node:
	def __init__(self, r, c):
		self.r = r
		self.c = c
		self.next = None

def main():
	N, K = input(int), input(int)
	apples = [[0]*(N+1) for _ in range(N+1)]
	for _ in range(K):
		r, c = map(int, input().split())
		apples[r][c] = 1

	snakes = [[False] * (N+1) for _ in range(N+1)]
	L, t = input(int), 0
	head = Node(1,1)
	tail = head
	snakes[1][1] = True
	end = False
	# E: 0, S: 1, W: 2, N: 3
	# L -> new_d = (prev_d - 1)%4, D -> new_d = (prev_d + 1)%4 
	direction, prev_X = 0, 0
	for i in range(L+1):
		if end:
			continue
		if i != L:
			X, C = input().split()
			X = int(X)
		else:
			X = 10000
			C = 'D'
		r, c = head.r, head.c
		# print('X is {}'.format(X))
		# print('direction is {}'.format(direction))
		for _ in range(X - prev_X):
			t += 1
			if direction%2: # N or S / direction == 1, 3
				r = r + 2 - direction
				if r > N or r < 1 or snakes[r][c]:
					end = True
					break
			else:        # E or W
				c = c + (1 - direction)
				if c > N or c < 1 or snakes[r][c]:
					end = True
					break
			# print(r, c)
			snakes[r][c] = True
			head.next = Node(r, c) 
			head = head.next
			if not apples[r][c]:
				snakes[tail.r][tail.c] = False
				tail = tail.next
			else:
				apples[r][c] = False

		add = -1
		if C == 'D':
			add = 1
		direction = (direction + add)%4 
		prev_X = X

	print(t)

main()
