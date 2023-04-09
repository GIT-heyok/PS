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
           ll l=INF,r=INF;
        ll n, w, h;
        cin >> n >> w >> h;
        ll cakes[n], dispenser[n];
        for (int i = 0; i < n; i++)
        {
            cin >> cakes[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> dispenser[i];
        }
        for (int i = 0; i < n; i++)
        {
            l = min(dispenser[i]-h-(cakes[i]-w), l);
            r = min(cakes[i]+w-(dispenser[i]+h),r);
        }
        // cout<<-l<< " "<<r<<endl;
        if(-l<=r){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }  
    }
}