import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	ans = 0
	for i in range(N):
		ans_t, temp = i, i
		while temp > 0:
			i += temp%10
			temp = temp//10
		if i == N:
			ans = ans_t
			break
	print(ans)
if __name__ == '__main__':
	main()