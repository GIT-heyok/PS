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
const ll INF = 1234567890ll;
int memo[MAX+1];
vector<pI> orig[MAX];
void build(int prev, int cur, int index){
    for (int i = 0; i < orig[cur].size(); i++)
    {
        int nextNode = orig[cur][i].first;
        int nextVal = orig[cur][i].second;
        if(nextNode!=prev){
            if(nextVal<index){
                memo[nextNode] = memo[cur]+1;  
            }
            else{
                memo[nextNode] = memo[cur];
            }
            build(cur, nextNode, nextVal);
        }
    }
    
}
int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            orig[i].clear();
            memo[i] = 1;
        }
        for (int i = 0; i < n-1; i++)
        {
            int a, b;
            cin >> a >> b;
            orig[a].push_back({b, i});
            orig[b].push_back({a, i});
        }
        build(1,1,-1);
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max(memo[i], ans);
            // cout<<memo[i]<<" ";
        }
        cout<<ans<<endl;
        
        

                    
    }
}