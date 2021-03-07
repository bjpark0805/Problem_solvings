import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N = input(int)
	stair_numbers = [1] * 10
	stair_numbers[0] = 0

	for i in range(2, N+1):
		temp = [0] * 10
		temp[0] = stair_numbers[1]
		for j in range(1, 9):
			temp[j] = (stair_numbers[j-1] + stair_numbers[j+1])%1000000000
		temp[9] = stair_numbers[8]
		stair_numbers = temp

	print(sum(stair_numbers)%1000000000)

main()