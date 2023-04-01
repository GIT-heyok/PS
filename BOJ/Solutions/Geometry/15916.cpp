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
const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main(){
	FAST
	int n;
    cin >> n;
    ll arr[n+1];
    arr[0]= 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ll k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        arr[i]-=k*i;
    }
    bool chk = false;
    if(arr[1]==0)chk=true;
    for (int i = 1; i < n; i++)
    {
        if((arr[i]<=0&&arr[i+1]>=0)||(arr[i]>=0&&arr[i+1]<=0))chk = true;
    }
    if(chk)cout<<"T"<<endl;
    else{
        cout<<"F"<<endl;
    }
    
    


    
}


