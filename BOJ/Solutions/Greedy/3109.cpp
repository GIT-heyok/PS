#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int n, m;
bool isWall[10000][500];
int dr[3] = {-1,0,1};
//int pp = 0;
bool dfs(int r, int c){
    //pp++;
    if(r>=0&&r<n&&c>=0&&c<m&&!isWall[r][c]){
        isWall[r][c] = true;
        if(c==m-1){
            return true;
        }
        for (int i = 0; i < 3; i++)
        {
            if(dfs(r+dr[i], c+1)){
                return true;
            }
        }
        return false;
    }
    else return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if(s[j]=='x'){
                isWall[i][j] = true;
            }
            else isWall[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(dfs(i,0)){
            ans++;
        }
    }
    cout<<ans<<endl;
/*


for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        cout<<isWall[i][j];
    }
    cout<<endl;
}
*/
//cout<<pp<<endl;

    

}