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
    
*/
int main() {
    FAST
    stack<char> st;
    string haystack, needle;
    cin >> haystack >> needle;
    for (int i = 0; i < haystack.length(); i++)
    {
        st.push(haystack[i]);
        stack<char> temp;
        while(!st.empty()){
            char ch = st.top();
            // cout<<ch<<endl;
            bool chk = true;
            if(ch==needle[needle.length()-1]&&st.size()>=needle.length()){
                temp.push(ch);
                st.pop();
                for (int i = needle.length()-2; i >=0; i--)
                {
                    ch = st.top();
                    // cout<<"?"<<ch<<endl;
                    st.pop();
                    temp.push(ch);
                    if(needle[i]!=ch){
                        // cout<<needle[i]<<" "<<ch<<endl;
                        chk = false;
                        break;
                    }
                }
                if(!chk)
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }       
                else
                    while(!temp.empty())temp.pop();         
            }            
            else break;
            if(!chk)break;
        }
    }
    string ans ="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(all(ans));
    if(ans.length()==0)cout<<"FRULA"<<endl;
    else cout<<ans<<endl;
}
