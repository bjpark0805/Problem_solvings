import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	price = list(map(int, input().split()))
	price.insert(0, 0)
	max_price = [0] * (N+1)
	max_price[1] = price[1]
	for i in range(2, N+1):
		tmp = 0
		for j in range(1, i+1):
			tmp = max(tmp, price[j]+max_price[i-j])
		max_price[i] = tmp
	print(max_price[N])

main()
