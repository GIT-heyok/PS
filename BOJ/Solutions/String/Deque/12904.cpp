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
const int MAX = 100001;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e9 + 7;

/*
reverse simulation.
*/
int main()
{
    FAST
    string s1, s2;
    cin >> s1 >> s2;
    deque<char> dq;
    for (int i = 0; i < s2.length(); i++)
    {
        dq.push_back(s2[i]);   
    }
    bool fromBack = true;
    while(dq.size()>s1.length()){
        char cur = ' ';
        if(fromBack){
            cur = dq.back();
            dq.pop_back();
        }
        else{
            cur = dq.front();
            dq.pop_front();
        }
        
        if(cur=='B'){
            fromBack = !fromBack;
        }
    }
    bool chk = true;
    if(fromBack){
        for (int i = 0; i < s1.length(); i++)
        {
            char ch = dq.front();
            dq.pop_front();
            if(ch!=s1[i])chk = false;
        }
         
    } 
    else{
        
        for (int i = 0; i < s1.length(); i++)
        {
            char ch = dq.back();
            dq.pop_back();
            if(ch!=s1[i])chk = false;
        }
    }
    cout<<chk<<endl;
}
