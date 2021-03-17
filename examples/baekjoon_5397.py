import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	T = input(int)
	for _ in range(T):
		string = input()
		l_list, r_list = [], []
		for s in string:
			if s == '<':
				if l_list: r_list.append(l_list.pop())
			elif s == '>':
				if r_list: l_list.append(r_list.pop())
			elif s == '-':
				if l_list: l_list.pop()
			else:
				l_list.append(s)

		print(''.join(l_list+list(reversed(r_list))))

main()