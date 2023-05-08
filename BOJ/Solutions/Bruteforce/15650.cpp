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
const int MAX = 9;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int n, m;
bool visited[MAX];
int arr[MAX];
void dfs(int cur, int depth){
    if(depth==0){
        for (int i = m; i >0; i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for (int i = cur+1; i <= n; i++)
        {
            if(!visited[i]){
                visited[i] = true;
                arr[depth] = i;
                dfs(i, depth-1);
                visited[i] =false;
            }
        }
        
    }
}

int main()
{
    FAST 
    cin >> n >> m;
    fill(visited, visited+MAX, false);
    dfs(0, m);
}
