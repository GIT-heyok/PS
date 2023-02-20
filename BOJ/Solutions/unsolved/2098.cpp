#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const int INF = 123456780;

int n;
int memo[17][1<<16];
int arr[16][16];

//cur: current location bit is visited bits
void dfs(int cur, int bit){
    int curMov = __builtin_popcount(bit); 
    // cout<<cur<<" "<<curMov<<" "<<bit<<endl;
    if(curMov==n-1){ //all done

        memo[0][bit+1] = min(memo[0][bit+1], memo[cur][bit]+arr[cur][0]);
        // cout<< cur<<" "<<0<<" "<<bit<< " "<<memo[0][bit+1] << endl;
        dfs(0, bit+1);
    }

    if(curMov==n){
        // cout<<"curVal: "<<memo[0][bit]<<endl;
        return;
    }
    for(int i=1; i<n; i++){
        if(!(bit&(1<<i))){
            int& a = memo[i][bit+(1<<i)];
            a = min(a, memo[cur][bit]+arr[cur][i]);
            // cout<< cur<<" "<<i<<" "<<bit<< " "<<a << endl;
            dfs(i, bit+(1<<i));
        }       
    }   
}

int main()
{
    FAST
    /*
    first implement the going part
    */
   cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==0)arr[i][j] = INF;
        }
    }
    fill(&memo[0][0], &memo[16][1<<16], INF);
    
    memo[0][0] = 0;
    dfs(0,0);
    int ans = INF;
    
    cout<<memo[0][(1<<n)-1]<<endl;
    
}