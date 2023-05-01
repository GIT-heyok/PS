#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e6 + 7;
const int MX = 1001;
int n, m, k;
struct Pos{
	int x, y, breakCount, cost; 
};
int breakCount[MX][MX]; // k + 1 로 초기화
bool board[MX][MX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int bfs() {
    queue<Pos> q;
    q.push(Pos{1, 1, 0, 1}); // x, y, breakCount, cost
    breakCount[1][1] = 0;
    
    while(!q.empty()) {
        Pos now = q.front();
        q.pop();
        
        if(now.x == n && now.y == m)
            return now.cost;
        
        for(int i = 0; i < 4; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            
            if(!isInRange(nx, ny)) continue;
            if(breakCount[nx][ny] <= now.breakCount) continue;
            
            if(board[nx][ny]) {
                if(now.breakCount >= k) continue;
               
                if(now.cost % 2 == 0) {  // night
                    q.push(Pos(now.x, now.y, now.breakCount, now.cost + 1));
                }
                else {  // day
                    breakCount[nx][ny] = now.breakCount;
                    q.push(Pos(nx, ny, now.breakCount + 1, now.cost + 1));
                }
            }
            else if(!board[nx][ny]) {
                breakCount[nx][ny] = now.breakCount;
                q.push(Pos(nx, ny, now.breakCount, now.cost + 1));
            }
        }
    }
    return -1;
}
int main()
{
    FAST 
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j]=s[i]-'0';
            breakCount[i][j]=k+1;
            
        }
        
    }
    
    cout<<bfs()<<endl;
    
    
}