import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

N, r, c = map(int, input().split())
cnt = 0

def recCount(r1, c1, N):
	global cnt
	if r1 == r and c1 == c:
		print(cnt)
		return
	if (r1 <= r < r1 + 2**(N-1)) and (c1 <= c < c1+2**(N-1)):
		recCount(r1, c1, N-1)
	elif (r1 <= r < r1 + 2**(N-1)) and (c1+2**(N-1) <= c < c1+2**N):
		cnt += 4**(N-1)
		recCount(r1, c1+2**(N-1), N-1)
	elif (r1 + 2**(N-1) <= r < r1 + 2**N) and (c1 <= c < c1+2**(N-1)):
		cnt += 4**(N-1) * 2
		recCount(r1+2**(N-1), c1, N-1)
	elif r1 + 2**(N-1) <= r and c1+2**(N-1) <= c:
		cnt += 4**(N-1) * 3
		recCount(r1+2**(N-1), c1+2**(N-1), N-1)

recCount(0, 0, N)

