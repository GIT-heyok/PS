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

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, c;
        cin >> n >> c;
        vector<vi> nodes(n+1);
        vi vec(n-1);
        for(int i=0; i<n-1; i++){
            cin >> vec[i];
        }
        for(int i=0;i<n-1; i++){
            int a, b;
            cin >> a>> b;
            nodes[a].emplace_back(b);
            nodes[b].emplace_back(a);
        }
        bool isBlack[n+1];
        for(int i=1; i<=n; i++){
            isBlack[i] = false;
        }
        isBlack[c] = true;
        int ans = INF;
        for(int i=0; i<n-1; i++){
            queue<pI> q;
            bool visited[n+1];
            for(int i=1; i<=n; i++){
                visited[i] = false;
            }
            q.push({vec[i],0});
            isBlack[vec[i]] = true;
            while(!q.empty()){
                int val = q.front().first;
                int dist = q.front().second;
                q.pop();
                visited[val] = true;
                if(isBlack[val]&&dist!=0){
                    ans = dist;
                    break;
                }
                for(int j=0; j<nodes[val].size(); j++){
                    if(!visited[nodes[val][j]]&&dist+1<ans){
                        q.push({nodes[val][j],dist+1});
                        visited[nodes[val][j]] = true;
                    }
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}