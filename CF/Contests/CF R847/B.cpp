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
        int n, s, r;
        cin >> n >> s>> r;
        int val = s-r;
        for(int i=1; i<=5; i++){
            if(r>=(n-1)*i&&r<=(n-1)*(i+1)){
                r-=(n-1)*i; // s now contains amount of over
                for(int j=0; j<n-r-1; j++){
                    cout<<i<<" ";
                }   
                for(int j=0; j<r; j++){
                    cout<< i+1<<" ";
                }
                cout<<val<<endl;
                break;
            }
        }
    }
}