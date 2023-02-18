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
        int n, a, b;
        cin>> n >>  a>>b;
        ll val = 1, mod = 1;
        bool flag = false;
        if(b==1){
            cout<<"Yes"<<endl;
        }
        else{
        while (val<=n)
        {
            if(mod==(n%b)){
                cout<<"Yes"<<endl;
                flag = true;
                break;
            }
            else{
                val*=a;
                mod = val%b;
            }
        }

        if(!flag)cout<<"No"<<endl;
        // cout<<n<<endl;
 
        }
          }

}