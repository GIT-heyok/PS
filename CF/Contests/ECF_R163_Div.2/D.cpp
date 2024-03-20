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
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int len = s.length();
        int r = len/2;
        int ans = 0;
        //l, r represents length/2 because string should be even
        for (int i = r; i >= 1; --i) {
            int mxlength = 0;
            int length = 0;
            for (int j = 0; j < len - i; ++j) {
                if(s[j]==s[j+i]||s[j]=='?'||s[j+i]=='?'){
                    length++;
                    mxlength = max(mxlength, length);
                }
                else{
                    length = 0;
                }
            }
            if(mxlength>=i){
                ans = i;
                break;
            }
        }
        cout<<ans*2<<endl;
    }
}
