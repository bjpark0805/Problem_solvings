import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	n = input(int)
	a, b = 1, 3
	for _ in range(n-2):
		a, b = b%10007, (2*a + b)%10007
	if n == 1:
		b = 1
	print(b)

main()