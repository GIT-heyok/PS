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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

int main()
{
    FAST
    string s;
    cin >> s;
    vector<string> vec;
    string temp = "";
    for (int i = s.length()-1; i>=0; i--)
    {
        temp = s[i]+temp;
        vec.push_back(temp);
    }
    sort(all(vec));
    for (string ss: vec)
    {
        cout<<ss<<endl;

    }
    
    
}

