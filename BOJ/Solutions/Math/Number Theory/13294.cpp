#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 100001;
int main() {
   FAST
   string s;
   cin >> s;
    if (s.length()<=6){
       int n = stoi(s);
       int cnt = 1;
       while(n>cnt){
           n/=cnt;
           cnt++;
       }
       cout<<cnt<<endl;
   }
    else{
        long double logVal = 0;
        for (int i = 1; i < 1000001; ++i) {
            logVal+=log10((long double)i);
            if(ceil(logVal)==s.length()){
                cout<<i<<endl;
                break;
            }
        }
    }
}