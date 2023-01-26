#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int INF = 1234567890;

//p: 1+...+k^p
ll getkPow(ll p, ll k){
    if(p<0)return 0; 
    ll sum =1;
    ll kPow = k;
    for(int i=0; i<p; i++){
        sum+=kPow;
        kPow*=k;
    }
    return sum;
}
ll getHeight(ll p, ll k){
    
}

ll getParent(ll n, ll k){
    if(n==1){ //edge case
        return 1;
    }
    else{
        int currentHeight = 1; 
        while(n>=getkPow(currentHeight-1, k)){
            currentHeight++;
        }
        currentHeight--;
        n-=getkPow(currentHeight-1, k);
        n+=k-1;
        n/=k;
        n+=getkPow(currentHeight-2,k);
        return n;
    }
}

int main(){
    FAST
//     for(int i=2; i<=15; i++){
//         cout<<i<<" "<<getParent(i,3)<<endl;
//     }
// //     cout<<getParent(7,2)<<endl;
// //     cout<<getParent(7,2)<<endl;
// //     cout<<getParent(7,2)<<endl;
// //     cout<<getParent(7,2)<<endl;
// //     cout<<getParent(7,2)<<endl;
    int n, k, q;
    cin >> n >> k >> q;
    if(k==1){
        while(q--){
            int a, b;
            cin >> a>>b;
            cout<<abs(a-b)<<endl;
        }
    }
    else{
        while(q--){
            ll a, b;
            cin >> a>>b;
            int length = 0;
            while(a!=b){
                // cout<<a<<" "<<b<<endl;
                if(b>a){
                    swap(a,b); //a는 항상 b보다 크다.
                }
                length++;
                a=getParent(a, k);
                // cout<<a<<endl;
            }
            cout<<length<<endl;
        }
    }
}
