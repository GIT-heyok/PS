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
        int n, k;
        cin >> n >>k;
        ll ans = 0;
        vll vec(n);
        for(int i=0; i<n; i++){
            ll a;
            cin >> a;
            ans+=a/k;
            vec[i] = a%k;
        }
        sort(all(vec));
        int l=0, r=n-1;
        while(l<r){
            if(vec[l]+vec[r]>=k){
                ans++;
                l++;
                r--;
            }
            else{
                l++;
            }
        }
        cout<<ans<<endl;
    }
}