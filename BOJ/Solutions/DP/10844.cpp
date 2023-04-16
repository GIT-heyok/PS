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
const ll MOD = 1e9;

int main(){
    FAST
    int n;
    cin >> n;
    ll arr[100][10];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 0;
        }
        
    }

    
    for (int i = 1; i < 10; i++)
    {
        arr[0][i] = 1;
    } 
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(j==0){
                arr[i+1][0]=arr[i][1];
            }
            else if(j==9){
                arr[i+1][9]=arr[i][8];
            }
            else{
                arr[i+1][j]+=arr[i][j-1];
                arr[i+1][j]+=arr[i][j+1];
            }
            arr[i][j]%=MOD;
        }
        
    }

   ll ans = 0;

    for (int i = 0; i < 10; i++)
    {
        ans+=arr[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
    
    
}