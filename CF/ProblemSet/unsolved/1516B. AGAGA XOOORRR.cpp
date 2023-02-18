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
#include <numeric>
 
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
        int n, arr[n];
        cin >>n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int cur = 0;
        bool flag = false;
        for (int i = 0; i < n-1; i++)
        {
            cur^=arr[i];
            int index =i+1;
            int val = 0;
            while(index<n){
                if(val==cur)val = 0;
                else {
                    val ^= arr[index];
                }
                index++;
            }
            if(val==cur){
                flag = true;
                break;
            }

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;        
                    
    }

}