#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
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
typedef pair<double, double> pD;
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        multiset<int> _map;
        for (int i = 0; i < n; i++)
        {
            char a;
            int b;
            cin >> a >> b;
            if(a=='I'){
                _map.insert(b);
            }
            else{
                if(!_map.empty()&&b==-1)_map.erase(_map.begin());
                else if(!_map.empty()&&b==1){
                    auto it = _map.end();
                    it--;
                    _map.erase(it);
                }
            }
        }
        if(_map.empty())cout<<"EMPTY"<<endl;
        else{
            auto end_it = _map.end();
            end_it--;
            cout<<(*end_it)<<" "<<(*_map.begin())<<endl;
        }
        
    }
}

