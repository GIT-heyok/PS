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
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;
int main() {
    FAST
    string s1, s2;
    cin >> s1 >> s2;
    int sz1 = s1.length(), sz2 = s2.length();
    int arr[sz2+1][sz1+1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= sz2; i++)
    {
        for (int j = 1; j <= sz1; j++)
        {
            if(s1[j-1]==s2[i-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{

                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    /*
    
    
    for (int i = 0; i < sz2+1; i++)
    {
        for (int j = 0; j < sz1+1; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int len = arr[sz2][sz1];
    cout<<len<<endl;
    vector<char> ans;
    int curR = sz2, curC = sz1;
    while(len>0){
        if(arr[curR][curC]>arr[curR][curC-1]){
            if(arr[curR][curC]>arr[curR-1][curC]){
                ans.push_back(s1[curC-1]);
                curR--;
                curC--;
                len--;
            }
            else{
                curR--;
            }
        }
        else curC--;

    }
    for (int i = ans.size()-1; i >=0; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
    
}