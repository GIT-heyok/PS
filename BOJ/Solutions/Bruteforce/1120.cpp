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
//maximum length of the intersect
int main()
{
    FAST 
    string s1, s2;
    cin >> s1 >> s2;
    int sz1 = s1.length(), sz2 = s2.length();
    int diffMin = 51;
    for (int i = 0; sz1+i <=sz2 ; i++)
    {
        int diff = 0;
        for (int j = 0; j < sz1; j++)
        {
            if(s1[j]!=s2[i+j])diff++;
        }
        diffMin = min(diffMin, diff);
    }
    cout<<diffMin<<endl;
    
}
