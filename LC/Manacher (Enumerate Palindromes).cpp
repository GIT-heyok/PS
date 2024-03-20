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
    string sinput;
    cin >> sinput;
    string s;
    s+= '!';
    for (int i = 0; i < sinput.length(); ++i) {
        s+= sinput[i];
        s+='!';
    }
    int n = s.length();
    vector<int> manacher(n);
    int p, r = -1;
    for (int i = 0; i < n; ++i) {
        if(i>r){
            p = r = i;
            while(r<n&&r<=2*p&&s[r]==s[2*p-r])
                r++;
            r--;
            manacher[i] = r-p;
        }
        else{
            int j = 2*p-i;
            if(manacher[j]<r-i){
                manacher[i] = manacher[j];
            }
            else if (manacher[j]> r-i){
                manacher[i] = r-i;
            }
            else{
                p = i;
                while(r<n&&r<=2*p&&s[r]==s[2*p-r])
                    r++;
                r--;
                manacher[i] = r-p;
            }

        }
    }
//    ll ans = 0;
//    for (int i = 0; i < n; ++i) {
//        cout<<s[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 1; i < n-1; ++i) {
        cout<<manacher[i]<<" ";
//        ans+=(manacher[i]+1)/2;
    }
//    cout<<ans<<endl;
}
