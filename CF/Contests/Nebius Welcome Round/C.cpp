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
        ll n, x, p;
        cin >> n >> x >> p;
        ll xx = min(n, p);
        ll init = x;
        bool chk = false;
        vi mod(n, INF);
        ll delta = 0;
        ll minim = INF;
        ll start = 0;
        for (int i = 1; i <= xx; i++)
        {
            start+=i;
            start%=n;
            mod[start] = min(mod[start],i);
            if((init+start)%n==0){chk = true;
            break;
            }      
            if(i==xx){
                delta = start;
            }
        }
        for (int i = 1; i < n; i++)
        {
            x+=delta;
            x%=n;
            if(mod[n-x]<INF){
                minim = i*n+mod[n-x];
                break;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<mod[i]<<" ";
        // }
        // cout<<endl;
        
        // cout<<delta<<" "<<minim<<" "<<mod[n-x]<<endl;
        if(!chk){
            if(minim<=p){
                chk = true;
            }
        }
        if(chk)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
         
    }
}