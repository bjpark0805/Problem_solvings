import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

N = input(int)
video = []
for _ in range(N):
	video.append(list(input()))
ans = []
def recQuad(r1, r2, c1, c2):
	if r2 == r1 + 1:
		ans.append(video[r1][c1])
		return
	n = video[r1][c1]
	for i in range(r1, r2):
		for j in range(c1, c2):
			if video[i][j] != n:
				ans.append('(')
				l = (r2-r1)//2
				recQuad(r1, r1+l, c1, c1+l)
				recQuad(r1, r1+l, c1+l, c2)
				recQuad(r1+l, r2, c1, c1+l)
				recQuad(r1+l, r2, c1+l, c2)
				ans.append(')')
				return
	ans.append(n)

recQuad(0, N, 0, N)
print(''.join(ans))