import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())
def main():
	N = input(int)
	max_line = [0,0,0]
	min_line = [0,0,0]
	for _ in range(N):
		a, b, c = list(map(int, input().split()))

		max_line = [a + max(max_line[0], max_line[1]), 
		b + max(max_line[0], max_line[1], max_line[2]), 
		c + max(max_line[1], max_line[2])]
		
		min_line = [a + min(min_line[0], min_line[1]), 
		b + min(min_line[0], min_line[1], min_line[2]), 
		c + min(min_line[1], min_line[2])]

	print(max(max_line), min(min_line))

if __name__ == '__main__':
	main()

