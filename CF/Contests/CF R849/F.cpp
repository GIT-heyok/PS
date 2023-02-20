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
const ll INF = 1234567890ll;
int sumDig(int n){
    int k=0;
    while(n>0){
        k+=n%10;
        n/=10;
    }
    return k;
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    FAST
    int T;
    cin >> T;
    // cout<<sumDig(10)<<endl;
    while(T--){
        int n, q;
        cin >> n >> q;
        vi vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }

        FenwickTree fw(n+2);
        for(int i=0; i<q; i++){
            int type;
            cin >> type;
            if(type==1){
                int l, r;
                cin >> l >> r;
                fw.add(l-1, 1);
                fw.add(r,-1);
            }
            else{
                int x;
                cin >> x;
                int temp = fw.sum(0, x-1);
                if(temp==0){
                    cout<<vec[x-1]<<endl;
                }
                else if(temp==1){
                    cout<<sumDig(vec[x-1])<<endl;
                }
                else if(temp==2){
                    cout<<sumDig(sumDig(vec[x-1]))<<endl;
                }
                else{
                    cout<<sumDig(sumDig(sumDig(vec[x-1])))<<endl;

                }
            }
        }
    }
}