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
const ll INF = 1234567890123ll;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        ll c;
        cin >> n >> c;
        vector<pLL> vec(n);
        for(int i=1; i<=n; i++){
            pLL temp = {0,i};
            cin >> temp.first;
            temp.first+=min(i, n+1-i);
            vec[i-1] = temp;
        }
        sort(all(vec));
        ll subSum[n];
        subSum[0] = vec[0].first;
        for(int i=1; i<n; i++){
            subSum[i] = subSum[i-1]+vec[i].first;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll tempC = c;
            ll val = vec[i].first;
            ll ind =vec[i].second;
            ll tempVal = val-min((int)ind,n+1-(int)ind)+ind;
            tempC-=tempVal;
            ll cnt;
            if(tempC>=0){
                cnt = upper_bound(subSum, subSum+n, tempC)-subSum+1;
                if(cnt>i){ //tempVal is counted twice
                    cnt = upper_bound(subSum, subSum+n, tempC+val)-subSum;
                }
                ans = max(cnt, ans);
            }
            
        }
        cout<<ans<<endl;
        

    }
}