#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const int INF = 123456780;
//inputting numbers in form of 2^k-1 except 1,2
ll arrMaxVal[32];
ll mxJump[32];

ll solve(ll l, ll r){
    cout<<"I: "<<l<< " "<< r<<endl;
    if(r==1)return 1;
    if(r==2) return 2;
    for (int i = 31; i >=0; i--)
    {
        if(l==arrMaxVal[i-1]&&r+1==arrMaxVal[i]){
            cout<<"!"<<endl;
            return mxJump[i-1];
        }
        if(r>=arrMaxVal[i]){
            cout<<arrMaxVal[i]<<" "<<mxJump[i]<<endl;
            if(l<arrMaxVal[i-1]){
                if(l>=arrMaxVal[i-2]){
                    return max(solve(l,arrMaxVal[i-1]-1ll), solve(arrMaxVal[i-1], r));
                }
                else{
                    return mxJump[i-1]+ solve(max(1ll, l-arrMaxVal[i-1]), max(1ll, r-arrMaxVal[i-1]));
                }
            }
            else{
                return mxJump[i-1]+solve(max(l-arrMaxVal[i-1],1ll), max(r-arrMaxVal[i-1],1ll));
            }
        }   
    }
    assert(false);    
    return -1;
}
int main()
{
    FAST
    int T;
    cin >> T;
    arrMaxVal[0] = 1;
    arrMaxVal[1] = 2;
    arrMaxVal[2] = 3;
    mxJump[0] = 1;
    mxJump[1] = 2;
    mxJump[2] = 4;
    for (int i = 3; i < 32; i++)
    {
        arrMaxVal[i] = arrMaxVal[i-1]*2+1;
        mxJump[i] = mxJump[i-1]+i;
    }
    
    // for (ll a: arrMaxVal)
    // {
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    // for (ll a: mxJump)
    // {
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    

    while(T--){
        int a, b;
        cin >> a >>b;
        cout<<solve(a,b)<<endl;
    } 
}