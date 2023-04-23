n, m, v = map(int, input().split())
arr = [[False]*(n+1) for i in range(n+1)]
for __ in range(m):
    a, b = map(int, input().split())
    arr[a][b]=True
    arr[b][a]=True

# DFS
visited = [False for i in range(n+1)]

def dfs(x):
    if not visited[x]:
        visited[x]=True
        print(x,end=" ")
        for i in range(1, n+1):
            if arr[x][i]:
                dfs(i)

dfs(v)
print()

# BFS
visited = [False for i in range(n+1)]
lst = [v]
while len(lst)>0:
    x = lst.pop(0)
    if visited[x]: continue
    visited[x]=True
    print(x, end=" ")
    for i in range(1,n+1):
        if arr[x][i]:
            lst.append(i)

print()