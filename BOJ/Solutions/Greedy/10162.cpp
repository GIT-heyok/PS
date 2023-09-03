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
    int arr[3] = {300,60,10};
    int n;
    cin >> n;
    if(n%10)cout<<-1<<endl;
    else{
        for (int i = 0; i < 3; i++)
        {
            cout<<n/arr[i]<<" ";
            n-=n/arr[i]*arr[i];
        }
        cout<<endl;

    }
}