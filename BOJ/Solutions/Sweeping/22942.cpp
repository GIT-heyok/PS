#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
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
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main(){
	FAST
    int n;
    cin>>n;
    vector<pI> circles;
    for (int i = 0; i < n; i++)
    {
        int x, r;
        cin >> x >> r;
        circles.push_back({x-r, x+r});
    }
    sort(all(circles));
    stack<int> s;
    bool chk = true;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty()&&s.top()<circles[i].first){
            // cout<<s.top()<<endl;
            s.pop();
        }
        if(s.empty()){
            s.push(circles[i].second);
        }       
        else{
            if(s.top()>circles[i].second){
                s.push(circles[i].second);
            }
            else{
                chk=false;
                break;
            }
        }
     
    }
    if(chk)cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
    }
    
    
}


