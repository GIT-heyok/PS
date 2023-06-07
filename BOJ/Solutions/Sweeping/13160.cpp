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
const int MAX = 16;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int main()
{
    FAST
    int n;
    cin >> n;
    vector<pI> vec;
    vector<pI> input;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a,0});
        vec.push_back({b,1});
        input.push_back({a,b});
    }
    sort(all(vec));
    int szmxm = 0;
    int szcur = 0;
    int idx = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        bool chk = vec[i].second;
        int aaa = vec[i].first;
        if(chk){
            szcur--;
        }   
        else{
            szcur++;
            if(szmxm<szcur){
                szmxm = szcur;
                idx = aaa;
            }
        }
    }
    cout<<szmxm<<endl;
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i].first<=idx&&input[i].second>=idx)cout<<i+1<<" ";
    }
    cout<<endl;
    
    
    
}