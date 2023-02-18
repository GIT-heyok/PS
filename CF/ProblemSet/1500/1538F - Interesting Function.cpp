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
#include <numeric>
 
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
        int l,r;
        cin >> l >> r;
        int pten = 1, ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += (r-(l-l%pten))/pten;
            pten*=10;
        }
        cout<<ans<<endl;
        
    }

}