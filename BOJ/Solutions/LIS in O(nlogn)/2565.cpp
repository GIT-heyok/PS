#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>

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
const int MAX = 500001;
const int INF = 1234567890;
int main()
{
    FAST
    int n;
    cin >> n;
    int arr[501];
    fill(arr, arr+501, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b] = a;
    }
    
    vi chk;
    for (int i = 1; i <=500; i++)
    {
        if(arr[i])chk.push_back(arr[i]);
    }
    
    vector<int> ans;
    ans.push_back(chk[0]);
    for (int i = 1; i < chk.size(); i++)
    {  
        if(ans[ans.size()-1]<chk[i]){
            ans.push_back(chk[i]);
        }   
        else{
            *lower_bound(all(ans), chk[i]) =  chk[i];
        }
    }
    cout<<n-ans.size()<<endl;
    
    
}

