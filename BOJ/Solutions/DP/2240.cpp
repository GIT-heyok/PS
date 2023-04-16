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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e6;

/*
jadu can be eaten when 2-> moved odd, 1-> moved even
memo[i][j] = max(memo[i-1][j-1]+((j)%2), memo[i-1][j]+(j+1)%2);
          
*/
int main(){
    FAST
    int t, w;
    cin >> t >> w;
    int memo[t][w+1];
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            memo[i][j] = 0;
        }
    }
    int jadu[t];
    for (int i = 0; i < t; i++)
    {
        cin >> jadu[i];
        jadu[i]--;
    }
    memo[0][0]=1-jadu[0];
    memo[0][1] = jadu[0];
    for (int i = 1; i < t; i++)
    {
        memo[i][0] = memo[i-1][0]+1-jadu[i];
        for (int j = 1; j < w+1; j++)
        {
            if(jadu[i]==0){
                //moving is better
                memo[i][j] = max(memo[i-1][j-1]+((j)%2), memo[i-1][j]+(j+1)%2);
            }   
            else{
                memo[i][j] = max(memo[i-1][j-1]+((j+1)%2), memo[i-1][j]+((j)%2));
            }
        }
        
    }
    int ans = 0;
    // for (int i = 0; i < t; i++)
    // {
    //     cout<<jadu[i]<<" : ";
    //     for (int j = 0; j < w+1; j++)
    //     {
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    for (int i = 0; i < w+1; i++)
    {
        ans = max(ans, memo[t-1][i]);
    }
    cout<<ans<<endl;
    
    
    
    
    
} 