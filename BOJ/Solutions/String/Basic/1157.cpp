#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;

int alphabet[26];

int main(void) {
    FAST
    string s;
    cin >> s;
    for (int i = 0; i < s.length() ; ++i) {
        if(s[i]<'a'){
            alphabet[s[i]-'A']++;
        }
        else{
            alphabet[s[i]-'a']++;
        }
    }
    int cnt = 0;
    vector<char> most;
    for (int i = 0; i < 26; ++i) {
        if(alphabet[i]>cnt){
            most.clear();
            most.push_back((char)i+'A');
            cnt = alphabet[i];
        }
        else if(alphabet[i]==cnt){
            most.push_back((char)i+'A');
        }
    }
    if(most.size()>1){
        cout<<"?"<<endl;
    }
    else{
        cout<<most[0]<<endl;
    }
}
