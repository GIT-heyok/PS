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
const int MAX = 201;

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

bool determine(int a, int b){
    return find(a)==find(b);
}
int main()
{
    FAST
    int n,m;
    cin >> n>>m;
    
    for(int i=1; i<=n; i++)parents[i]= i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a;
            cin >> a;
            if(a==1){
                merge(i,j);
            }
        }
    }
    bool chk = true;
    int base;
    cin >>base;
    for(int i=1; i<m; i++){
        int temp;
        cin>> temp;
        if(!determine(base,temp))chk=false;
    }
        // for(int i=1; i<=n; i++){
        //     cout<<parents[i]<<" ";
        // }
        // cout<<endl;
    if(chk)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}









