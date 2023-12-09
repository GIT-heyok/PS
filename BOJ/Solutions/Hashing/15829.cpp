#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'


int main()
{
    FAST
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long k = 0;
    for (int i = s.length()-1; i >= 0; --i) {
        k*=31;
        k += s[i]-'a'+1;
        k%=1234567891;
    }
    cout<<k<<endl;
}


