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
        int n, q;
        cin >> n >> q;
        bool isOdd[n];
        int numOdd[n+1];
        numOdd[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            isOdd[i] = temp%2==1;
            if(isOdd[i])numOdd[i+1]=numOdd[i]+1;
            else numOdd[i+1]=numOdd[i];
        }
        for (int i = 0; i < q; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int odd = numOdd[b]-numOdd[a-1];
            int cur = numOdd[n]-odd;
            if(c%2==1){
                cur+=(b-a+1);
            }
            if(cur%2==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        

        
    }
}