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
        int n;
        cin >> n;
        if(n%2!=0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for (int i = 0; i < n/2; ++i) {
                if(i%2==0)
                    cout<<"AA";
                else cout<<"BB";
            }
            cout<<endl;
        }
    }
}
