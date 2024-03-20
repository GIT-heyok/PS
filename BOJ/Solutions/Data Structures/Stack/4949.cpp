#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;

int main(void) {
    FAST
    string s;
    while(getline(cin, s)){
        if(s==".")break;
        stack<char> q;
        bool chk = true;
        for (int i = 0; i < s.length(); ++i) {
            if(s[i]=='('){
                q.push('(');
            }
            else if(s[i]=='['){
                q.push('[');
            }
            else if(s[i]==')'){
                if(q.empty()||q.top()=='['){
                    chk = false;
                    break;
                }
                q.pop();
            }
            else if(s[i]==']'){
                if(q.empty()||q.top()=='('){
                    chk = false;
                    break;
                }
                q.pop();
            }
        }
        if(chk&&q.empty())cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
