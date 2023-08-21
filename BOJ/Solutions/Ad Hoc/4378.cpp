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
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;
int main() {
    FAST
    string ref = "AVXSWDFGUHJKNBIOQEARYCQZTZ";
    
    string s;
    while(getline(cin, s)){
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='A'&&s[i]<='Z'){
            cout<<ref[s[i]-'A'];
        }
        else if(s[i]==' ')cout<<' ';
        else if(s[i]=='[')cout<<'P';
        else if(s[i]==']')cout<<'[';
        else if(s[i]=='\\')cout<<']';
        else if(s[i]==';')cout<<'L';
        else if(s[i]=='.')cout<<',';
        else if(s[i]=='/')cout<<'.';
        else if(s[i]==',')cout<<'M';
        else if(s[i]=='\'')cout<<';';
        else if(s[i]=='-')cout<<'0';
        else if(s[i]>='2'&&s[i]<='9')cout<<(char)(s[i]-1);
        else if(s[i]=='1')cout<<'`';
        else if(s[i]=='0')cout<<'9';
        else if(s[i]=='=')cout<<"-";
        else cout<<"NOT HANDLED";
    }
    }
    
}