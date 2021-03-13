import sys
def input(_type=str):
	return _type(sys.stdin.readline().strip())

def main():
	N, HATK = map(int, input().split())
	rooms = [tuple(map(int, input().split())) for _ in range(N)]
	minv, maxv = 0, sum([(r[2]//HATK) * r[1] if r[0] == 1 else 0 for r in rooms])+1
	while minv + 1 < maxv:
		midv = (minv + maxv)//2
		CurHP, CurATK = midv, HATK
		success = True
		for ti, ai, hi in rooms:
			if ti == 1:
				CurHP -= ai * (hi//CurATK) if hi % CurATK else ai*(hi//CurATK - 1)
				if CurHP <= 0:
					success = False
					break
			else:
				CurHP, CurATK = min(midv, CurHP + hi), CurATK + ai
		if not success:
			minv = midv + 1
		else:
			maxv = midv
	
	CurHP, CurATK = minv, HATK
	success = True
	for ti, ai, hi in rooms:
		if ti == 1:
			CurHP -= ai * (hi//CurATK) if hi % CurATK else ai*(hi//CurATK - 1)
			if CurHP <= 0:
				success = False
				break
		else:
			CurHP, CurATK = min(minv, CurHP + hi), CurATK + ai

	if success:
		maxv = minv
	print(maxv)

main()