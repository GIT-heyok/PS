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
const ll INF = 12345670;

int main()
{
    FAST
    int K;
    cin >> K;
    while(K--){
        int v, e;
        cin >> v>> e;
        vi visited(v+1, -1);
        vector<vi> vec(v+1, vi());
        for(int i=0; i<e; i++){
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        queue<int> q;
        bool flag = true;
        for(int i=1; i<=v; i++){
            if(visited[i]==-1){
                q.push(i);
                visited[i] = 0;
                
                while(!q.empty()){
                    int temp = q.front();
                    // cout<<temp<<" "<<visited[temp]<<endl;

                    q.pop();
                    for(int i: vec[temp]){
                        if(i!=temp&&visited[i]==visited[temp]){
                            flag = false;
                        }
                        else if(i!=temp&&visited[i]==-1){
                            visited[i] = !visited[temp];
                            q.push(i);
                        }
                    }
                }
            }
            else if(!flag) break;
        }
       
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
