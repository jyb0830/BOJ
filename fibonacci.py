def fibonacci(n):
    if n==0:
        return memo[0]
    elif n==1:
        return memo[1]

    else:
        if memo[n][0]!=0 or memo[n][1]!=0:
            return memo[n]
        if memo[n-1][0]!=0 or memo[n-1][1]!=0:
            memo[n]=[memo[n-2][0]+memo[n-1][0], memo[n-1][0]+memo[n-1][1]]
            return memo[n]


        return fibonacci(n-2)[0]+fibonacci(n-1)[0],fibonacci(n-2)[1]+fibonacci(n-1)[1]




memo = [[0 for col in range(2)] for row in range(41)]
memo[0][0]=1
memo[1][1]=1

t = int(input())
ans = [[0 for i in range(2)] for j in range(t)]
for i in range(t):
    ans[i]=fibonacci(int(input()))

for i in range(t):
    print(ans[i][0],ans[i][1])
