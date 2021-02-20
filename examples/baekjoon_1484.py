import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	G = input(int)
	i, j, cnt = 1, 2, 0
	while j <= G//2+1:
		if j**2 - i **2 >= G:
			if j**2 - i **2 == G:
				print(j)
				cnt += 1
			i += 1
		else:
			j += 1
	
	if cnt == 0:
		print(-1)

if __name__ == '__main__':
	main()
