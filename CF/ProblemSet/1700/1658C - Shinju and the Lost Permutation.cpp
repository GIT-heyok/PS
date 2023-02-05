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
        cin >> n;
        vi vec(n);
        int oneIndex = -1, oneCount = 0;
        for(int i=0; i<n; i++)
        {
            cin >> vec[i];
            if(vec[i]==1){
                oneIndex = i;
                oneCount++;
            }
        }    
        if(oneCount!=1){
            cout<<"NO"<<endl;
        } 
        else{
            bool flag = true;
            int prev = vec[oneIndex]; //prev should be one
            for(int i=1; i<n; i++){
                int cur =vec[(oneIndex+i)%n];
                if(prev<cur){
                    if(cur-prev!=1){
                        flag = false;
                        break;
                    }
                }
                prev = cur;
            } 
            if(flag){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
       
    }
}