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
const int MAX = 1000010;

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
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        parents[i] = i;
    }    
    for(int i=0; i<m; i++){
        int type, a, b;
        cin >> type >> a >>b;
        if(type==0){
            merge(a,b);
            // for(int i=0; i<=n; i++)
            // cout<<parents[i]<<" ";
            // cout<<endl;
        }
        else{
            string s = determine(a,b)?"YES":"NO";
            cout<<s<<endl;
        }
    }
}









