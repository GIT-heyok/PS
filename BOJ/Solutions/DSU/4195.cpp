#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 200001;

int parents[MAX];
int cnt[MAX];
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
    if(a1!=b1){
        parents[b1] = a1;
        cnt[a1] += cnt[b1];
    }
}

bool determine(int a, int b){
    return find(a)==find(b);
}

int getCount(int a){
    return cnt[find(a)];
}
int main()
{
    FAST
    int T;
    cin >>T;
    while(T--){
        int n;
        cin >> n;
        map<string, int> m;
        int mapSize =0;
        for(int i=1; i<=2*n; i++){
            parents[i] = i;
            cnt[i] = 1;
        }
        for(int i=0; i<n; i++){
            string s1, s2;
            cin >>s1 >>s2;
            if(m[s1]==0)m[s1] = ++mapSize;
            if(m[s2]==0)m[s2] = ++mapSize;
            int a = m[s1], b = m[s2];
            merge(a,b);
            cout<<getCount(a)<<endl;
        }
        
        // for(int i=1; i<=2*n; i++){
        //     cout<<parents[i]<<" "; 
        // }
        // cout<<endl;
        // for(int i=1; i<=2*n; i++){
        //     cout<<cnt[i]<<" "; 
        // }
        // cout<<endl;
    }
    
}









