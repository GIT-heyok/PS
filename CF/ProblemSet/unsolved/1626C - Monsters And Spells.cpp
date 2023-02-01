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
const int INF = 1234567890;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        
        vll time(n+1), health(n+1);
        time[0] = -1000
        ;
        health[0] = 0;
        for(int i=1; i<=n; i++){
            cin>>time[i];
        } for(int i=1; i<=n; i++){
            cin>>health[i];
        }   
        ll curMax = health[n];
        ll cur = curMax;
        ll ans = 0;
        for(int i=n-1; i>=0; i--){
            ll h = health[i];
            ll dt = time[i+1]-time[i];
            if(cur-dt<=0){
                ans += (curMax*(curMax+1))/2;
                curMax = h;
            }
            else if(cur-dt<h){
                curMax += h-(cur-dt);
            }
            cur=h;
        }
        cout<<ans<<endl;

    }
}