import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

candidate = []
def filter(query, s, b):
	global candidate
	temp = []
	for i in range(len(candidate)):
		s_n, b_n = 0, 0
		for j in range(3):
			s_n += 1 if candidate[i][j] == query[j] else 0
			b_n += 1 if candidate[i][j] == query[(j+1)%3] or candidate[i][j] == query[(j+2)%3] else 0
		if s == s_n and b == b_n:
			temp.append(candidate[i]) 
	candidate = temp
		

def main():
	N = input(int)
	global candidate
	questions = []
	for i in range(1, 10):
		for j in range(1, 10):
			for k in range(1, 10):
				if i == j or i == k or j == k:
					continue
				candidate.append([i, j, k])

	for _ in range(N):
		query, s, b = input().split()
		query, s, b = list(map(int, list(query))), int(s), int(b)
		filter(query, s, b)	

	print(len(candidate))

main()