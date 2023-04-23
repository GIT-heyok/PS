n = int(input())
arr1 = [0]
for i in range(n):
    temp = int(input())
    arr1.append(temp)
arr2 = [0]
for i in range(n):
    temp = int(input())
    arr2.append(temp)

memo = [[0]*(n+1) for i in range(n+1)]

for i in range(1,n+1):
    for j in range(1, n+1):
        memo[i][j] = max(memo[i-1][j], memo[i][j-1])
        if(abs(arr1[i]-arr2[j])<=4):
            memo[i][j] = max(memo[i][j], memo[i-1][j-1]+1)

print(memo[n][n])