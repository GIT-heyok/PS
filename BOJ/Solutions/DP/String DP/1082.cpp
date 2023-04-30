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

const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;
int cmp(string s1, string s2){
    if(s1.length()==s2.length())
        return s1>s2;
    return s1.length()-s2.length();   
}

/*
consider the number as string and compare them.
exclude zeros cause they are confusing.
and dp[i] = max(dp[1]+dp[i-1], dp[2]+dp[i-2],..., dp[i-1]+dp[i])
(has to do it twice cause it is string concat)
... and put as much zeros as possible per memo
and print the maximum value of memo

*/
int main()
{
    FAST;
    int n;
    cin >> n;
    int cost[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    int m;
    cin >> m;
    if(n==1){
        cout<<0<<endl;
    }
    else{
        string memo[m+1];
        for (int i = 0; i < m+1; i++)
        {
            memo[i]="";
        }
        for (int i = 1; i < n; i++)
        {
            if(cost[i]<=m&&cmp(to_string(i),memo[cost[i]])>0){
                memo[cost[i]] = to_string(i);
            }
        }
        
        for (int i = 1; i < m+1; i++)
        {
            string& ss = memo[i];
            for (int j = 1; j < i; j++)
            {
                string s1 = memo[j]+memo[i-j];
                string s2 = memo[i-j]+memo[j];
                if(cmp(s1, ss)>0){
                    ss = s1;
                }
                if(cmp(s2, ss)>0){
                    ss = s2;
                }
            }       
        }
        string ans ="";
        for (int i = 0; i <= m; i++)
        {
            
                string tmp = memo[m-i];
            if(memo[m-i]!=""){
                for (int j = cost[0]; j <= i; j+=cost[0])
                {
                    tmp+="0";
                }
                
            }
            if(cmp(tmp,ans)>0)ans = tmp;
        }
        if(ans=="")cout<<0<<endl;
        else cout<<ans<<endl;
        
    }
    


    
    
}