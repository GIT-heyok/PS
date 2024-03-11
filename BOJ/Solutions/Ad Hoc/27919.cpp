#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
int main(void) {
    FAST
    string s;
    cin >> s;
    int u=0, p=0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='C'||s[i]=='U'){
            u++;
        }
        else p++;
    }
    if(u>(p+1)/2){
        cout<<"U";
    }
    if(p>0){
        cout<<"DP"<<endl;
    }

}
