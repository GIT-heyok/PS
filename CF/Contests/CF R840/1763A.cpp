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
        int bitCnt[10];
        for(int i=0; i<10; i++){
            bitCnt[i] = 0;
        }       
        for(int i=0; i<n; i++){
            int temp;
            cin >>temp;
            for(int j=0; j<10; j++){
                if(temp&(1<<j)){
                    bitCnt[j]++;
                }
            }
        }

        int mxm = 0;
        for(int i=0; i<10; i++){
            if(bitCnt[i]>0){
                mxm+=(1<<i);
            }
            if(bitCnt[i]==n){
                mxm-=(1<<i);
            }
        }
        cout<<mxm<<endl;
        
    }
}