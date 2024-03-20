//#include <bits/stdc++.h>
#include <iostream>

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
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='c'||s[i]=='s'||s[i]=='d'||s[i]=='z') {
            if(i+1<s.length()){
                if(s[i+1]>='a'&&s[i+1]<='z'){
                    if(s[i]=='d'&&s[i+1]=='z'&&i+2<s.length()&&s[i+2]=='='){
                        i+=2; //dz=
                    }
                }
                else{
                     i++;  //c=, c-, d-, s=, z-
                }

            }
        }
        else if(s[i]=='l'||s[i]=='n'){
            if(i+1<s.length()&&s[i+1]=='j')
                i++; //lj, nj
        }
        cnt++;
    }
    cout<<cnt<<endl;
}
