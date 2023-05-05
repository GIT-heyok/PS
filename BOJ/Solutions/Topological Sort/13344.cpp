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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int N, M;
int parents[MAX];

int find(int a){
    if(parents[a]==a)return a;
    return parents[a] = find(parents[a]);
}

void merge(int a, int b){
    if(a>b){
        swap(a,b);
    }
    int a1 = find(a);
    int b1 = find(b);
    parents[b1] = a1;
}
//union find + topological sort
int main()
{
    FAST 
    cin >> N >>  M;

    vector<pI> query;
    for (int i = 1; i <= N; i++)
    {
        parents[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        string comp;
        cin >> a >> comp >> b;
        if(comp=="="){
            merge(a, b);
        }
        else{
            query.push_back({a,b});
        }
    } 
    bool chk[N];
    for (int i = 0; i < N; i++)
    {
        chk[parents[i]]=true;
    }
    vector<int> grp;
    int converter[N];
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if(chk[i]){
            grp.push_back(i);       
            converter[i]=cnt;
            cnt++;
        }
    }
    bool ans = true;
    vector<int> graph[cnt];
    int inDegree[cnt];
    for (int i = 0; i < cnt; i++)
    {
        inDegree[i] = false;
    }
    
    for (auto a:query)
    {
        int fir = a.first;
        int sec = a.second;
        if(find(fir)==find(sec)){
            ans = false;
            break;
        }
        else{
            int gr1 = converter[find(fir)];
            int gr2 = converter[find(sec)];
            graph[gr1].push_back(gr2);
            inDegree[gr2]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < cnt; i++)
    {
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    bool visited[cnt];
    for (int i = 0; i < cnt; i++)
    {
        visited[i] = false;
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        visited[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            inDegree[next]--;
            if(inDegree[next]==0&&!visited[next])
                q.push(next);
        }
        
    }
    
    for (int i = 0; i < cnt; i++)
    {
        if(!visited[i])ans=false;
    }
    if(ans){
        cout<<"consistent"<<endl;
    }
    else{
        cout<<"inconsistent"<<endl;
    }
    
    
    

    
    
    
    

    
    

}
