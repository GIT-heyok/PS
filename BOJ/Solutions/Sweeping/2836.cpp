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
    int n;
    ll m;
    cin >> n >> m;
    ll ans = m;
    vector<pLL> comeBack;
    for(int i=0; i<n;i++){
        ll a, b;
        cin >> a>>b;
        if(a>b){
            comeBack.push_back({b,a});
        }
    }
    sort(all(comeBack));
    ll s1=-INF, s2=-INF;
    for(auto temp: comeBack){
        if(s1<=temp.first&&s2>=temp.first){
            s2 = max(s2,temp.second);
        }
        else{ //정렬이 되어 있으므로 더 클 수 밖에 없다.
            ans+=(s2-s1)*2;
            s1 = temp.first, s2 = temp.second;
        }
    }
    ans+=(s2-s1)*2;
    cout<<ans<<endl;


}