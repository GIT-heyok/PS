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
    int T;
    cin >> T;
    while(T--) {
        long long x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1==x2&&y2==y1) {
            if (r1 == r2)cout << -1 << endl;
            else cout << 0 << endl;
        }
        else{
            long long radSum = (r2+r1)*(r2+r1);
            long long radDiff = (r2-r1)*(r2-r1);
            long long centerDiff = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
            if(radDiff==centerDiff)
                cout<<1<<endl;
            else if(radSum==centerDiff)cout<<1<<endl;
            else if(radSum>centerDiff&&radDiff<centerDiff)
                cout<<2<<endl;
            else cout<<0<<endl;
        }

    }
}


