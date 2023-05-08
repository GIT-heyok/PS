#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

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
typedef pair<double, double> pD;
const int MAX = 1;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
ll merge(vi& vec, int l1, int r1, int l2, int r2){
    vi temp;
    ll ans =0;
    /* l1 is the smallest in vector1
     l2 is the smallest in vector2
     and the limit is r1 and r2*/
    int indA=l1, indB=l2;
    while(indA<=r1&&indB<=r2){
        if(vec[indA]>vec[indB]){
            ans+=r1-indA+1;
            temp.emplace_back(vec[indB]);
            indB++;
        }
        else{
            temp.emplace_back(vec[indA]);
            indA++;
        }
    }
    while(indA<=r1){
        temp.emplace_back(vec[indA]);
        indA++;
    }
    while(indB<=r2){
        temp.emplace_back(vec[indB]);
        indB++;
    }
    int index = 0;
    for(int i=l1;i<=r2; i++,index++){
        vec[i] = temp[index];
    }
    return ans;
}
//divide and merge!
ll mergeSort(vi& vec, int l, int r){
    if(l==r)return 0;
    else{
        // cout<<l<<" "<<r<<endl;
        ll ans = 0;
        int mid=(l+r)/2;
        ans += mergeSort(vec, l, mid);
        ans += mergeSort(vec, mid+1, r);
        //divided successfully.
        ans+=merge(vec, l,mid, mid+1, r);
        return ans;
    }
           
}
int main(){
    FAST
    while(true){
        int n;
        cin >> n;
        if(n==0)break;
        vector<int> vec(n);
        ll ans = 0;
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }
        ans = mergeSort(vec, 0, n-1);
        cout<<ans<<endl;
    }
}