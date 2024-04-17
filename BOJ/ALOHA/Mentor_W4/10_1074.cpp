#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

// 1074 Z
int divide(int depth, int r1, int c1, int r2, int c2, int r, int c){
    if(depth==-1)return 0;
    int plus = 1<<depth;
    int add = plus*plus;
    if(r<r1+plus){
        // O O
        // X X
        if(c<c1+plus){
            // O X
            // X X : 0
            return divide(depth-1, r1, c1, r1+plus, c1+plus, r, c);
        }
        else{
            // X O
            // X X : 1
            return add+divide(depth-1, r1, c1+plus, r1+plus, c2, r, c);
        }
    }
    else{
        // X X
        // O O
        if(c<c1+plus){
            //2
            return 2*add+divide(depth-1, r1+plus, c1, r2, c1+plus, r, c);
        }
        else{
            return 3*add+divide(depth-1, r1+plus, c1+plus, r2, c2, r, c);
        }
    }
}

int main()
{
    FAST
    int n, r, c;
    cin >> n >> r >>c;
    cout<<divide(n-1,0,0,1<<n,1<<n,r,c);
}
