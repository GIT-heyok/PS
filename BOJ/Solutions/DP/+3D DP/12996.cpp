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

const int MAX = 501;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9+7;



int main()
{
    FAST;
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int dx[7] = {1,0,0,1,1,0,1}; 
    int dy[7] = {0,1,0,1,0,1,1}; 
    int dz[7] = {0,0,1,0,1,1,1};
    ll memo[n+1][x+1][y+1][z+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < x+1; j++)
        {
            for (int k = 0; k < y+1; k++)
            {
                for (int l = 0; l < z+1; l++)
                {
                    memo[i][j][k][l] = 0;
                }
                
            }
            
        }
        
    }
    memo[0][0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x+1; j++)
        {
            for (int k = 0; k < y+1; k++)
            {
                for (int l = 0; l < z+1; l++)
                {
                    for (int m = 0; m < 7; m++)
                    {
                        int tempx = j+dx[m];
                        int tempy = k+dy[m];
                        int tempz = l+dz[m];
                        if(tempx<=x&&tempy<=y&&tempz<=z){
                            
                            memo[i+1][tempx][tempy][tempz] += memo[i][j][k][l];
                            memo[i+1][tempx][tempy][tempz]%=MOD;
                            
                        }
                    }
                    
                }
                
            }
            
        }
        
    }
    cout<<memo[n][x][y][z]<<endl;
    
    
}