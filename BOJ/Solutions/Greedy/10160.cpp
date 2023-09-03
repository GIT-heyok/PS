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
    int arr[10];
    memset(arr, 0, sizeof(arr));
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]-'0']++;
    }
    bool chk1 = arr[0];
    int chk2 = 0;
    for (int i = 0; i < 10; i++)
    {
        chk2 += arr[i]*i;
    }
    chk2%=3;
    if(chk1&&!chk2){
        for (int i = 9; i >= 0 ; i--)
        {
            while(arr[i]){
                cout<<i;
                arr[i]--;
            }
        }
    }
    else cout<<-1<<endl;
    
    
}