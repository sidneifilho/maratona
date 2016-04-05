# count the number of '1' in the binary form of the input
T = int(input())

while(T):
	num = int(input())
	
	cnt = 0
	while(num):
		num &= (num-1)
		cnt+=1

	print(cnt)

	T-=1