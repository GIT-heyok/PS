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

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if(k==0){
            for(int i=0; i<n/2; i++){
                cout<<i<<" "<<n-1-i<<endl;
            }
        }
        else if(k<n-1){
            //match n-1 and k
            // match 0 with n-k-1
            //match everything else
            cout<<n-1<<" "<<k<<endl;
            cout<<0<<" "<<n-k-1<<endl;
            for(int i=1; i<n/2; i++){
                if(i==n-k-1||i==k){
                    continue;
                }
                cout<<i<<" "<<n-1-i<<endl;
            }
        }
        else{
            if(n==4)cout<<-1<<endl;
            else{
                //match n-1 and n-2
                //match 1 and n-3
                //match 0 and 2
                //match from 3 to n/2
                cout<<n-1<<" "<<n-2<<endl;
                cout<<1<<" "<<n-3<<endl;
                cout<<0<<" "<<2<<endl;
                for(int i=3; i<n/2; i++){
                    cout<<i<< " "<<n-1-i<<endl;
                }
            }   
        }
    }
}