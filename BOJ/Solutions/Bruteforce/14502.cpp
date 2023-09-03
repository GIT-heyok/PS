#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main()
{
    FAST
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < n*m; i++)
    {
        int r1 = i/m, c1 = i%m;
        if(arr[r1][c1])continue;
        arr[r1][c1] = 1;
        for (int j = i+1; j < n*m; j++)
        {
            int r2 = j/m, c2 = j%m;
            if(arr[r2][c2])continue;
            arr[r2][c2] = 1;
            for (int k = j+1; k < n*m; k++)
            {
                int r3 = k/m, c3 = k%m;
                if(arr[r3][c3])continue;
                arr[r3][c3] = 1;
                int temp[n][m];
                queue<pair<int,int>> q;
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
                        temp[r][c] = arr[r][c];
                        if(temp[r][c] == 2)q.push({r,c});
                    }
                }
                
                while(!q.empty()){
                    int curR = q.front().first;
                    int curC = q.front().second;
                    q.pop();
                    for (int type = 0; type < 4; type++)
                    {
                        int newR = curR+dr[type];
                        int newC = curC+dc[type];
                        if(newR>=0&&newR<n&&newC>=0&&newC<m&&temp[newR][newC]==0){
                            temp[newR][newC] = 2;
                            q.push({newR, newC});
                        }
                    }
                }
                int cnt = 0;
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
                        if(temp[r][c]==0)cnt++;
                    }
                }
                ans = max(ans, cnt);
                arr[r3][c3] = 0;
            }
            
            arr[r2][c2] = 0;
        }
        arr[r1][c1] = 0;
    }
    cout<<ans<<endl;
}