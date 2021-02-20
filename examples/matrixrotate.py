def rotatematrix(num):
	m = [[1,2,3],[4,5,6],[7,8,9]]
	# m = [[1,2,3,4,5],[6,7,8,9,0],[1,2,3,4,5],[6,7,8,9,0],[1,2,3,4,5]]
	n = len(m)
	def rotate(m):
		rotated = [[0 for _ in range(n)] for _ in range(n)]
		for i in range(n):
			for j in range(n):
				if i == j or n - 1 - i == j:
					rotated[i][j] = m[i][j]
				else:
					rotated[j][n - 1 - i] = m[i][j]
		return rotated
	num %= 4
	for _ in range(num):
		m = rotate(m)

	for i in range(n):
		for j in range(n):
			print(m[i][j], end = ' ')
		print()



if __name__ == '__main__':
	num = int(input())
	rotatematrix(num)
