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
        string s;
        cin >> s;
        int cnt = 0;
        int mxcnt = 0;
        char prev = '!';
        for (int i = 0; i < n; i++)
        {
            char cur = s[i];
            if(cur!=prev){
                cnt = 1;
                prev = cur;
            }
            else{
                cnt++;
            }
            mxcnt = max(mxcnt,cnt);
        }
        cout<<mxcnt+1<<endl;
        

        
    }
}