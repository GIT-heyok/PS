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
    string s1, s2;
    cin >> s1 >> s2;
    string s = s2+s1;
    int n = s.length();
    vector<int> Z(n);
    int l = 0, r = 0;
    Z[0] = n;
    for (int i = 1; i < n; ++i) {
        if(i < r){
            Z[i] = min(r-i, Z[i-l]);
        }
        while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]]){
            Z[i]++;
        }
        if(i+Z[i]>r){
            l = i;
            r = i+Z[i];
        }
    }
    int cnt = 0;
    for (int i = s2.length(); i < n; ++i) {
        if(Z[i]>=s2.length()){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

