#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>

#include <iomanip>
#include <set>
#include <map>
#include <cmath>

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
const int MAX = 500001;
const ll INF = 1234567890123ll;

void getNext(string& s, int k){
    int last = s.length()-1;
    s[last]++;
    for (int i = last; i >=0; i--)
    {
        if(s[i]-'a'==k){
            s[i-1]++;
            s[i] = 'a';
        }
    }
    
}
int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        map<string, bool> m;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        for (int i = 0; i+b-1 < a; i++)
        {
            string temp = "";
            for (int j = 0; j < b; j++)
            {
                temp += s[i+j];
            }
            m[temp] = true;   
        }
        string ans = "";
        for (int i = 0; i < b; i++)
        {
            ans+='a';
        }
        
        while(m[ans]){
            getNext(ans, c);
        }
        cout<<ans<<endl;
        
         
    }	
}

