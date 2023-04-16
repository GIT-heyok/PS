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
    int n, arr[3];
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    int memo[n+1];
    fill(memo, &memo[n+1], -1);
    memo[0] = 0;
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            if(i-arr[k]>=0&&memo[i-arr[k]]!=-1){
                memo[i] = max(memo[i], memo[i-arr[k]]+1);
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout<<memo[i]<<" ";
    // }
    
    cout<<memo[n]<<endl;
    
    
}