def main():
	t = int(input())
	for i in range(t):
		x1, y1, x2, y2 = tuple(map(int, input().split()))
		n = int(input())
		ans = 0
		for j in range(n):
			cx, cy, r = tuple(map(int, input().split()))
			if (x1 - cx)**2 + (y1 - cy)**2 < r**2 and (x2 - cx)**2 + (y2 - cy)**2 > r**2 or \
			(x1 - cx)**2 + (y1 - cy)**2 > r**2 and (x2 - cx)**2 + (y2 - cy)**2 < r**2:
				ans += 1
		print(ans)



if __name__ == "__main__":
	main()