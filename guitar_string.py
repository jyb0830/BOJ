n, m = map(int, input().split())

buy_one=[0 for i in range(m)]
buy_six=[0 for i in range(m)]
for i in range(m):
    buy_six[i],buy_one[i]=map(int, input().split())

cost = 0

min_one = min(buy_one)
min_six = min(buy_six)

if min_one*6<min_six:
    cost+=n*min_one

else :
    cost += int(n/6)*min_six
    if (n%6)*min_one>min_six:
        cost += min_six
    else:
        cost += (n%6)*min_one

print(cost)