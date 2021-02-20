import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())
def main():
	n, k = list(map(int, input().split()))
	coins = [0]
	for _ in range(n):
		coins.append(input(int))
	coins.sort()

	ans = [0] * (k+1) 
	for i in range(k+1):
		ans[i] = 1 if not i % coins[1] else 0 # 동전 1번까지 써서 0~k원까지 만드는 방법
	for i in range(2, n+1):
		for j in range(k+1):
			if j+coins[i] > k:
				break
			ans[j+coins[i]] += ans[j]
	print(ans[k])
	
main()

