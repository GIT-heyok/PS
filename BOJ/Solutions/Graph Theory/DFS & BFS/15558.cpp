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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;


int main()
{
    FAST
    int n, k;
    cin >> n >> k;
    bool arr[2][n];
    int clrCondition = inf;
    int chk[2][n];
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j]-'0';
            chk[i][j] = inf;
        }
    }
    chk[0][0] = 0;
    queue<pI> q;
    q.push({0,0});
    bool chkk = false;
    while(!q.empty()){
        int curRow = q.front().first;
        int curCol = q.front().second;
        // cout<<curRow<<" "<<curCol<<endl;
        q.pop();
        int currentSpot = chk[curRow][curCol];
        if(currentSpot<curCol-1){
            if(curCol-1>=0&&chk[curRow][curCol-1]>currentSpot+1&&arr[curRow][curCol-1]){
                chk[curRow][curCol-1] = currentSpot+1;
                q.push({curRow, curCol-1});                
            }
        }

        if(curCol+k>=n){
            chkk = true;
            break;
        }

        if(chk[curRow][curCol+1]>currentSpot+1&&arr[curRow][curCol+1]){
            chk[curRow][curCol+1] = currentSpot+1;
            q.push({curRow, curCol+1});
        }
        if(chk[!curRow][curCol+k]>currentSpot+1&&arr[!curRow][curCol+k]){
            chk[!curRow][curCol+k] = currentSpot+1;
            q.push({!curRow, curCol+k});
        }
    }
    cout<<chkk<<endl;
}