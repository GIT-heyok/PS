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
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int n;
    cin >> n;
    n = 1000-n;
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        ans+=n/arr[i];
        n-=n/arr[i]*arr[i];
    }
    cout<<ans<<endl;
    
}