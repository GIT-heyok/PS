#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main()
{
    FAST
    int n;
    string s;
    cin >> n >> s;
    int arr[n][4];
    int mnm = 1e9;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < 4; ++k) {
                arr[j][k] = 0;
            }
        }
        for (int j = 0; j < s.length(); ++j) {
            if(s[j]=='C'){
                arr[j%i][0]++;
            }
            else if(s[j]=='G'){
                arr[j%i][1]++;
            }
            else if(s[j]=='A'){
                arr[j%i][2]++;
            }
            else{
                arr[j%i][3]++;
            }
        }
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            int mx = max(arr[j][0], max(arr[j][1], max(arr[j][2],arr[j][3])));
            sum += arr[j][0]+arr[j][1]+arr[j][2]+arr[j][3]-mx;
        }
        mnm = min(sum,mnm);
    }
    cout<<mnm<<endl;
}
