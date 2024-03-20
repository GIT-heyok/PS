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
    int n;
    cin >> n;
    auto cmp = [](const string& a, const string& b) {
        if(a.length()<b.length())return true;
        else if(a.length()>b.length())return false;
        else return a<b;
    };
    set<string, decltype(cmp)> st(cmp);
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        st.insert(temp);
    }
    for (auto a: st) {
        cout<<a<<endl;
    }
}
