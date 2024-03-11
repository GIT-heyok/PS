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
    int alphabetlocation[26];
    for (int i = 0; i < 26; ++i) {
        alphabetlocation[i] = 100;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        alphabetlocation[s[i]-'a'] = min(alphabetlocation[s[i]-'a'], i);
    }
    for (int i = 0; i < 26; ++i) {
        if(alphabetlocation[i]<100){
            cout<<alphabetlocation[i]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
}
