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
        int ans = 0;
        int a, b;
        cin >> a>> b;
        a = abs(a);
        b = abs(b);
        ans = min(a,b)*2;
        // cout<<a<< " "<< b<<endl;
        a-=ans/2;
        b-=ans/2;
        ans+=max(0,a*2-1);
        ans+=max(0,b*2-1);
        cout<<ans<<endl;
    
    }
}