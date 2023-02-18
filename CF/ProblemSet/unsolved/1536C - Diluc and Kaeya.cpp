#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int MAX = 500001;
const int INF = 1234567890;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int d[n+1];
        fill(d, d+n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            // cout<<s[i-1];
            d[i] = d[i-1]+(s[i-1]=='D'?1:0);
        }
        // cout<<endl;
        
        int ans[n+1];
        fill(ans, ans+n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            int now = 1;
            ans[i] = max(ans[i], now);
            int curd = d[i];
            for (int j = 2; i*j<= n; j++)
            {
                if(d[i*j]==curd*j){
                    ans[i*j] = max(ans[i*j], now*j);
                }
                else break;
            }
            
        }
       for (int i = 1; i < n+1; i++)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;
  
        for (int i = 1; i < n+1; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
               
    }

}