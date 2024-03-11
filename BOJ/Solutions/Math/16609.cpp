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
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    bool chk = false;
    double mnm = 1;
    for (int i = 1; i <= n; ++i) {
        if(vec[i-1]>i)chk=true;
        mnm = min(mnm, (double)vec[i-1]/i);
    }
    cout<<setprecision(10)<<fixed;
    if(chk){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<mnm<<endl;
    }
}
