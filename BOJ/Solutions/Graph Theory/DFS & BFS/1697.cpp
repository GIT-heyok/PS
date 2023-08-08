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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int main()
{
    FAST
    int n, k;
    cin >> n >> k;
    int arr[400000];
    for (int i = 0; i < 400000; i++)
    {
        arr[i] = inf;
    }
    arr[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(2*cur<400000&&arr[2*cur]>arr[cur]+1){
            arr[2*cur] = arr[cur]+1;
            q.push(2*cur);
        }
        if(cur+1<400000&&arr[cur+1]>arr[cur]+1){
            arr[cur+1] = arr[cur]+1;
            q.push(cur+1);
        }
        if(cur-1>=0&&arr[cur-1]>arr[cur]+1){
            arr[cur-1] = arr[cur]+1;
            q.push(cur-1);
        }
    }
    cout<<arr[k]<<endl;
}