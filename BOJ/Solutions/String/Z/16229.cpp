#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

/*
 * 30 1
abcdefgabcdefgabcdefgabcdefgab

30 5
abcdefgabcdefgabcdefgabcdefgab

30 4
abcdefgabcdefgabcdefgabcdefgab

30 12
abcdefgabcdefgabcdefgabcdefgab
 edge cases
 */
typedef long long ll;
int main(void) {
    FAST
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z(n);
    z[0]=  n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if(i < r){
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r = i+z[i];
        }
    }

    if(k>=n){
        cout<<n<<endl;
    }
    else{
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if(z[n-i]==i){
                if((n-i)*2<=n+k&&(n%(n-i)==0||(n-i-(n-(n/(n-i)*(n-i)))<=k))){
                    ans = max(ans,n-i);
                }
            }
        }
        cout<<ans<<endl;
    }
//    for (int i = 0; i < n; ++i) {
//        cout<<z[i]<<" ";
//    }
//    cout<<endl;
}

