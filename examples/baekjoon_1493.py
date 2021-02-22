import sys
import math
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	"""
	Do not have to calculate all the cases.
	Count cases from the biggest one and keep replace the case with smaller one.
	"""
	l,w,h= map(int, input().split())
	N = input(int)
	cubes = [0] * 20
	for _ in range(N):
		A, B = map(int, input().split())
		cubes[A] = B
	cnt, ans = 0, 0
	for i in range(19, -1, -1):
		cnt <<= 3
		temp = (l>>i) * (w>>i) * (h>>i) - cnt
		ans += min(cubes[i], temp)
		cnt += min(cubes[i], temp)
	if cnt != l * w * h:
		ans = -1
	print(ans)

main()

"""
My first solution: 
-> calculate all the cases. 

import sys
import math
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	squares= [sorted(list(map(int, input().split())))]

	N = input(int)
	cubes = []
	for _ in range(N):
		A, B = list(map(int, input().split()))
		cubes.append([(2**A), B])
	cubes.sort(key=lambda x:x[0], reverse = True)
	ans = 0
	while squares:
		sq = squares[0]
		unable = True
		for i in range(len(cubes)):
			if cubes[i][1] <= 0:
				continue
			if cubes[i][0] <= sq[0]:
				# print(sq)
				unable = False
				# cube_idx = i+1
				n1 = min(cubes[i][1], sq[0]//cubes[i][0])
				n2 = min(cubes[i][1]//n1, sq[1]//cubes[i][0])
				n3 = min(cubes[i][1]//(n1*n2), sq[2]//cubes[i][0])
				ans += n1*n2*n3
				cubes[i][1] -= n1*n2*n3

				if sq[2]-n3*cubes[i][0] > 0:
					squares.append(sorted([sq[2]-n3*cubes[i][0], sq[0], sq[1]]))
				if sq[0]-n1*cubes[i][0] > 0:
					squares.append(sorted([sq[0]-n1*cubes[i][0], sq[1], n3*cubes[i][0]]))
				if sq[1]-n2*cubes[i][0] > 0:
					squares.append(sorted([sq[1]-n2*cubes[i][0], n1*cubes[i][0], n3*cubes[i][0]]))
				del squares[0]
				if cubes[i][1] <= 0:
					del cubes[i]
				break
		if unable:
			ans = -1
			break
	print(ans)

main()
"""
