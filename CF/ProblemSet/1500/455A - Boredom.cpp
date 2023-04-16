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
constexpr int MAX = 100002;
// memo[i] = max(memo[i-1], memo[i-2]+arr[i]*i);
int main(){
    FAST
    int n;
    cin >> n;
    ll arr[MAX];
    fill(arr, arr+MAX, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    
    ll memo[MAX];
    fill(memo, memo+MAX, -1);
    memo[0] = 0;
    memo[1] = arr[1];
    for (ll i = 2; i < MAX; i++)
    {   
        memo[i] = max(memo[i-1], memo[i-2]+arr[i]*i);
    }
    cout<<memo[MAX-1]<<endl;
    
}