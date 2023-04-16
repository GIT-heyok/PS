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
#include <memory.h>

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
typedef pair<double, double> pD;

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e6;


//count by coins!!!
int main(){
    FAST 
    int n, k;
    cin >> n >> k;
    int memo[k+1];
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    fill(memo, memo+k+1, 0);
    memo[0]=1;
    for (int i = 0; i < n; i++)
    {
         
        for (int j = 0; j <= k; j++)
        {
            if(j-arr[i]>=0){
                memo[j] += memo[j-arr[i]];
            }    
    
        }
        
    }
    
    cout<<memo[k]<<endl;
    
    
} 
