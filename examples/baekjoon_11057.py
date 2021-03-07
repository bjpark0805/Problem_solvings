import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	up_num = [1] * 10
	for _ in range(N-1):
		tmp = [0] * 10
		for i in range(10):
			tmp[i] = sum(up_num[:i+1])%10007
		up_num = tmp
	print(sum(up_num)%10007)

main()