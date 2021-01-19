n=int(input())

ans = [0 for i in range(n)]
for i in range(n):
    x1,y1,r1,x2,y2,r2 = map(int, input().split())
    dist = (x1-x2)**2 + (y1-y2)**2
    if dist == 0 :
        if r1==r2:
            ans[i]=-1
            continue
        else:
            ans[i]=0
            continue

    else:
        if dist==(r1-r2)**2 or dist==(r1+r2)**2:
            ans[i]=1
            continue

        elif dist>(r1+r2)**2 or dist < (r1-r2)**2:
            ans[i]=0
            continue

        elif dist<(r1+r2)**2:
            ans[i]=2

for i in range(len(ans)):
    print(ans[i])