#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;

int states[10][2] = {
        {1,3},
        {7,2},
        {1, 3},
        {4, 7},
        {5, 7},
        {5, 6},
        {1, 8},
        {7, 7},
        {9, 8},
        {5, 2},
};
int main(void) {
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int node = 0;
        for (int j = 0; j < s.length(); ++j) {
            if(s[j]=='0'){
                node = states[node][0];
            }
            else{
                node = states[node][1];
            }
        }
        if(node==2||node==6||node==8){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
