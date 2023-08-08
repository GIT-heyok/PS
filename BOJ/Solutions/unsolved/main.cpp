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
vector<int> pi(1000001);

void failure(string& s){
    int m = 0;
    int begin = 1;
    for (int i = 0; i < s.length(); i++)
    {
        pi[i] = 0;
    }
    
    while(begin+m<s.length()){
        if(s[begin+m]==s[m]){
            m++;
            pi[begin+m-1]=m;
        }
        else{
            if(m==0)begin++;
            else begin+=m-pi[m-1],m=pi[m-1];
        }
    }
}

vector<int> KMP(string& a, string& b){
    int j = 0;
    failure(b);
    vector<int> ans;
    for (int i = 0; i < a.length(); i++)
    {
        while(j>0&&a[i]!=b[j]){
            j = pi[j-1];
        }
        if(a[i]==b[j]){
            if(j==b.length()-1){
                ans.push_back(i-b.length()+1);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    FAST
    int n;
    cin >> n;
    string lst[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >>temp>>lst[i];
    }
    string finalString;
    int sz;
    cin >> sz >> finalString;
    int dp[n+1][sz];
    int ub = sz;
    for (int i = 0; i < sz; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            dp[i][j] = inf;
        }
        
    }
    
    
    for (int i = 0; i < n; i++)
    {
        vector<int> vec = KMP(finalString, lst[i]);
        for (int j = 0; j < vec.size(); j++)
        {
            dp[i+1][vec[j]] = max(dp[i][vec[j]],(int)lst[i].length());
            cout<<i+1<<" "<<vec[j]<<" "<<dp[i+1][vec[j]]<<endl;
        }
        if(vec.size()>0)
            ub = min(ub, vec[vec.size()-1]);
        int cur = lst[i].length();
        cout<<ub<<" "<<cur<<endl;
        for (int j = ub; j >= 0; j--)
        {
         //   cout<<i+1<<" "<<j <<" "<<dp[i+1][j]<<" "<<cur<<endl;
            
                dp[i+1][j] = max(dp[i][j],cur);
               cur++;
            if(dp[i+1][j]<inf){
                cur = lst[i].length();
            }
            else{
                if(dp[i][j]<cur&&i>0){
                    cur = dp[i][j];
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    

    
}