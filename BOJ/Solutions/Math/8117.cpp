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
    vector<int> sides;
    int temp;
    cin >>temp;
    while(temp!=0){
        sides.push_back(temp);
        cin >> temp;
    }
    sort(sides.begin(), sides.end());
    bool chk = false;
    for (int i = 0; i < sides.size() - 2; ++i) {
        if(sides[i]+ sides[i+1]>sides[i+2]){
            cout<<sides[i]<<" "<<sides[i+1]<<" "<<sides[i+2]<<endl;
            chk = true;
            break;
        }
    }
    if(!chk)cout<<"NIE"<<endl;
}
