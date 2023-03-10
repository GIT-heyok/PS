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

bool memo[2001][2001], visited[2001][2001];
int arr[2001];

bool isPalindrome(int s, int e){
    if(visited[s][e]){
        return memo[s][e];
    }
    visited[s][e] = true;
    bool& temp = memo[s][e];
    if(s==e)return temp = true;
    if(arr[s]==arr[e]){
        if(s+1==e)return temp=true;
        return temp = isPalindrome(s+1, e-1);
    }
    else{
        return temp = false;
    }
}
int main()
{
    FAST
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    

    fill(&memo[0][0],&memo[n][n+1], false);
    
    fill(&visited[0][0],&visited[n][n+1], false);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout<<isPalindrome(s, e)<<endl;
    }
        
}

