import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, d, k, c = list(map(int, input().split()))
	kind = [0]*(d+1)
	sushi = []
	for _ in range(N):
		sushi.append(input(int))
	sushi *= 2
	num_kind = 0
	for i in range(k):
		num_kind += 0 if kind[sushi[i]] else 1
		kind[sushi[i]] += 1
	ans = num_kind

	for i in range(N):
		coupon = 1 if kind[c] == 0 else 0
		ans = max(ans, num_kind + coupon)
		
		kind[sushi[i]] -= 1
		num_kind -= 1 if not kind[sushi[i]] else 0		
		num_kind += 1 if not kind[sushi[i+k]] else 0
		kind[sushi[i+k]] += 1
		
	print(ans)

if __name__ == '__main__':
	main()
