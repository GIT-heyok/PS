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
        int ans = 0;
        string s;
        cin >> s;
        for(int i=0; i<n; i++){
            int val;
            bool chk=false;
            int conv = 0;
            if(s[i]=='+'){
                chk = false;
                val = 1;
            }
            else{
                chk = true;
                val = -1;
            }
            for(int j=i+1; j<n; j++){
                if(s[j]=='+'){
                    chk = false;
                    val++;
                }
                else{
                    if(chk){
                        chk = false;
                        conv++;
                    }
                    else chk = true;
                    val--;
                }
                if(val<=0&&val+3*conv>=0&&(val+3*conv)%3==0){
                    ans++;
                }
            }

        }
            cout<<ans<<endl;
    }
}