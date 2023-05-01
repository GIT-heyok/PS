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

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        sort(all(vec));
        if(vec[0]!=1){
            cout<<"NO"<<endl;
        }
        else{
            ll mxm = 1;
            bool chk = true;
            for (int i = 1; i <n; i++)
            {
                if(vec[i]>mxm){
                    chk = false;
                }
                else{
                    mxm+=vec[i];
                }
            }
            if(chk)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
    }
}