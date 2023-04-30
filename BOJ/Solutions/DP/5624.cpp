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

const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;

/*
A+B = D-C
*/
int main()
{
    FAST;
    int n;
    cin >> n;

    bool visited[MAX];
    fill(visited, visited+MAX, 0);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(visited[arr[i]-arr[j]+100000]){
                result++;
                break;
            }
        }

        for (int j = 0; j <= i; j++)
        {
            visited[arr[i]+arr[j]+100000]=true;
        }
    }
    cout<<result<<endl;
    
    
}