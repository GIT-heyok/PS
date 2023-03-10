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

string delChunk(string s, int index){
    string ans = "";

    for (int i = 0; i < index; i++)
    {
        ans+=s[i];    
    }
    char cur = s[index];    
    while(++index<s.length()){
        if(s[index]!=cur){
            break;
        }
    }
    for (size_t i = index; i < s.length(); i++)
    {
        ans+=s[i];       
    }
    return ans;
}

bool dfs(string s){
    if(s=="")return true;
    bool ans = false;
    for (int index = 0; index < s.length();)
    {
        char cur = s[index];
        int i2 = index;
        while(true){
            index++;
            // cout<<index<<" " <<s[index]<<" !"<<endl;
            if(index>=s.length()||s[index]!=cur){
                break;
            }
        } 
        // cout<<index<<" "<<i2<<endl;

        if(index-i2>=2){
            // cout<<s<<" "<<i2<<" "<<index<<endl;
            ans |= dfs(delChunk(s,i2));
            if(ans==true)break;
        }

    }
    return ans; 
}
int main()
{
    FAST 
    int T;
    cin >> T;
    // cout<<delChunk("bb",0)<<endl;
    while(T--){
        string s;
        cin >> s;
        cout<<dfs(s)<<endl;
    }
}

