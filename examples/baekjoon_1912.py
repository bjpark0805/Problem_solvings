import sys
def input(_type = str):
	return _type(sys.stdin.readline().strip())

# 어떤 구간까지의 합이 음수가 되면 그전걸 사용할 필요가 없음 -> 초기
def main():
	N = input(int)
	numbers = list(map(int, input().split()))
	psum = [numbers[0]]
	ans = numbers[0]
	for i in range(1, len(numbers)):
		psum.append(max(numbers[i], psum[-1]+numbers[i]))
		ans = max(ans, psum[-1])
	print(ans)
	
def original_sol():
	N = input(int)
	numbers = list(map(int, input().split()))
	p_sum, max_v, partial_sum = 0, -1001, []
	for n in numbers:
		max_v = max(max_v, n)
		p_sum += n
		partial_sum.append(p_sum)
	min_v, ans = 0, 0
	for ps in partial_sum:
		min_v = min(min_v, ps)
		ans = max(ans, ps - min_v)
	ans = max_v if ans <= 0 else ans 
	print(ans)
if __name__ == '__main__':
	main()



