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
        int n;
        string s;
        cin >> n >>s;
        int ind = -1;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                ind = i;
                break;
            }}
        if(ind==-1){
            cout<<2<<" "<<n/2+1<<" "<<1 <<" "<<n/2<<endl;
        }
        else{
            if(ind<n/2){
                cout<<ind+2<<" "<<n<<" "<<ind+1<<" "<<n<<endl;
            }
            else{
                cout<<1<<" "<<ind+1<<" "<<1<<" "<<ind<<endl;
            }
        }

       
    }
}