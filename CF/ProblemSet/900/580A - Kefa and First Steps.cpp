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
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
int main(){
    FAST
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    int cur = arr[0];
    int curSz = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>=cur){
            curSz++;
            ans = max(ans, curSz);
        }
        else{
            curSz = 1;
        }
        cur = arr[i];
    }
    cout<<ans<<endl;
    
    
}