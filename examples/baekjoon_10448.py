import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def triangle(K):
	nums = [1]
	s, i = 1, 1
	while s+i+1 < K:
		i += 1
		s += i
		nums.append(s)
	for i in range(len(nums)):
		for j in range(len(nums)):
			for k in range(len(nums)):
				if nums[i]+nums[j]+nums[k]==K:
					return 1
	return 0

def main():
	T = input(int)
	for _ in range(T):
		K = input(int)
		print(triangle(K))

main()