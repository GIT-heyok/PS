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
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            bool chk = true;
            int steps = 1;
            int a = n;
            int b = i;
            while(steps<=k){
                if(b<0){
                    chk = false;
                    break;
                }
                else{
                    int temp = a-b;
                    a = b;
                    b = temp; 
                }
                steps++;
            }
            if(chk){
            ans++;}
        }
        cout<<ans<<endl;
        
        
    }
}