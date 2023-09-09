#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 1000;
const int INF = 987654321;

    int n, s, r;
    int arr[1001];
int main() {    
    FAST
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        s ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            int temp = s ^ arr[i] ^ (arr[i]-j);
            r+= temp==0;
        }
        
    }
    cout<<r<<endl;
    
    
}