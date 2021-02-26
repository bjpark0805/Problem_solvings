import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	paper = []
	count = {'-1':0, '0':0, '1':0}
	for _ in range(N):
		paper.append(input().split())
	def recCount(r1, r2, c1, c2):
		n = paper[r1][c1]
		if r2 - r1 == 1:
			count[n] += 1
			return
		for i in range(r1, r2):
			for j in range(c1, c2):
				if paper[i][j] != n:
					l = (r2 - r1)//3
					for i in range(3):
						for j in range(3):
							recCount(r1+i*l, r1+(i+1)*l, c1+j*l, c1+(j+1)*l)
					return			
		count[n] += 1

	recCount(0, N, 0, N)
	for k, v in count.items():
		print(v)

main()