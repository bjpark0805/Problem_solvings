import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

candy_table = []

def calculate_max():
	global candy_table
	ans = 0
	for i in range(len(candy_table)):
		max_len = 1
		for j in range(len(candy_table[0])-1):
			max_len = max_len + 1 if candy_table[i][j] == candy_table[i][j+1] else 1
			ans = max(ans, max_len)

	for j in range(len(candy_table[0])):
		max_len = 1
		for i in range(len(candy_table) - 1):
			max_len = max_len + 1 if candy_table[i][j] == candy_table[i+1][j] else 1
			ans = max(ans, max_len)

	return ans

def main():
	N = input(int)
	global candy_table
	for _ in range(N):
		l = input()
		candy_table.append(list(l))
	ans = 2
	for i in range(len(candy_table)):
		for j in range(len(candy_table[0])-1):
			if candy_table[i][j] == candy_table[i][j+1]:
				continue
			candy_table[i][j], candy_table[i][j+1] = candy_table[i][j+1], candy_table[i][j]
			ans = max(calculate_max(), ans)
			candy_table[i][j], candy_table[i][j+1] = candy_table[i][j+1], candy_table[i][j]
	for i in range(len(candy_table)-1):
		for j in range(len(candy_table[0])):
			if candy_table[i][j] == candy_table[i+1][j]:
				continue
			candy_table[i][j], candy_table[i+1][j] = candy_table[i+1][j], candy_table[i][j]
			ans = max(calculate_max(), ans)
			candy_table[i][j], candy_table[i+1][j] = candy_table[i+1][j], candy_table[i][j]

	print(ans)

if __name__=='__main__':
	main()