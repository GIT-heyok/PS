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
const int INF = 123456780;

int main()
{
    FAST
    int n;
    cin >> n;
    ll arr[n+1];
    arr[0] = 0;
    for (int i = 1; i < n+1; i++)
    {
        cin  >> arr[i];
        arr[i]+= arr[i-1];
    }
    int ansK=0;
    ll ans = 99999999;
    vll temp;
    for (int k = 1; k < n; k++)
    {
        temp.clear();
        
        for (int j = 0; j+k <=n ; j++)
        {
            temp.push_back(arr[j+k]-arr[j]);
        }
        // for (int i = 0; i < temp.size(); i++)
        // {
        //     cout<<temp[i]<<" ";
        // }
        
        // cout<<endl;
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = i+k; j < temp.size(); j++)
            {
                // cout << i << " " << j <<" "<< abs(temp[j]-temp[i])<<endl;
                if(ans>=abs(temp[j]-temp[i])){
                    ansK = k;
                    ans = abs(temp[j]-temp[i]);
                }
            }
        }
        
           
    }
    cout<<ansK<<endl;
    cout<<ans<<endl;
    
     
}