#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
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
const int INF = 1234567890;
vector<int> efwef;
int binarySearch(vi& a, int n, int m, vi* ans){
    int l=0, r = 30000;
    int k = 30000; //최댓값이다.
    vector<int> vv;
    vector<int>* vvptr = &vv;
    while(l<=r){
        vvptr->clear();
        vvptr->push_back(0);
        int mid = (l+r)/2;
        int temp = m;
        int index = 0;
        while(temp--&&index<n){
            int subSum = 0;
            while(subSum<=mid&&index<n){
                subSum+=a[index];
                if(subSum>mid){
                    index--;
                }
                index++;
            } 
            vvptr->push_back(index);
        }
        if(index==n){ //최댓값이 너무 크다.
            if(k>mid){
                k = mid;
                ans->clear();
                for(int a: *vvptr){
                    ans->push_back(a);
                }
            }
            r=mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return k;
}
int main()
{
    FAST
    int n, m;
    cin >> n>>m;
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<binarySearch(a, n, m, &efwef)<<endl;
    for(int i=0; i<efwef.size()-1; i++){
        cout<<efwef[i+1]-efwef[i]<<" ";
    }
    cout<<endl;
}
