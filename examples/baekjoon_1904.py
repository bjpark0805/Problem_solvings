import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	a, b = 1, 2
	for i in range(2, N):
		a, b = b%15746, (a+b)%15746
	if N == 1:
		b = 1
	print(b)

main()