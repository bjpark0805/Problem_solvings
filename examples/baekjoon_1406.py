import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

class Node():
	def __init__(self, v=-1, n=None, p=None):
		self.val = v
		self.nxt = n
		self.prev = p


def main():
	string, M = input(), input(int)
	head = Node()
	cursor = head
	for s in string:
		tmp = Node(v = s, p = cursor)
		cursor.nxt = tmp
		cursor = tmp
	last = cursor

	for _ in range(M):
		s = input()
		if s[0] == 'L':
			if cursor.prev != None:
				cursor = cursor.prev
		elif s[0] == 'D':
			if cursor.nxt != None:
				cursor = cursor.nxt
		elif s[0] == 'B':
			if cursor.prev == None:
				continue
			elif cursor.nxt == None:
				cursor = cursor.prev
				cursor.nxt = None
			else:
				p, n = cursor.prev, cursor.nxt 
				p.nxt, n.prev = n, p
				cursor = p
		else:
			tmp = Node(v = s[2], n = cursor.nxt, p = cursor)
			if cursor.nxt != None:
				cursor.nxt.prev, cursor.nxt = tmp, tmp
			else:
				cursor.nxt = tmp
			cursor = tmp

	cursor = head.nxt
	while cursor != None:
		print(cursor.val, end="")
		cursor = cursor.nxt

main()
