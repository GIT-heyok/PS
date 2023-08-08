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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
int main()
{
    FAST
    
    string s;
    cin >> s;
    char c = s[0];
    bool chk = true;
    for (int i = 0; i < s.length(); i++)
    {
        if(c!=s[i])chk = false;
    }
    if(chk){
        cout<<"-1"<<endl;
    }
    else{
        bool chk2 = true;
        int ptr1 = 0, ptr2 = s.length()-1;
        while(ptr1<ptr2){
            if(s[ptr1]==s[ptr2]){
                ptr1++;
                ptr2--;
            }
            else{
                chk2 = false;
                break;
            }
        }
        if(chk2)cout<<s.length()-1<<endl;
        else cout<<s.length()<<endl;
    }
    
}