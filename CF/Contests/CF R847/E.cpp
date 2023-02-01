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
        bool chk = true;
        int prev = 1;
        for(int i=0; i<32; i++){
            if(!(n&(1<<i))){//zero
                prev = 0;
            }
            else{ //one
                if(prev==1){
                    chk = false;
                    break;
                }
                prev = 1;
            }
        }
        if(chk){
            cout<<n+n/2<<" "<<n/2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}