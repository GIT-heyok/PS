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

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const int max = 500001;
const ll inf = 1234567890123ll;

int main()
{
    fast
    int n;
    cin >> n;
    int arr[n];
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vec.push_back(arr[0]);
    int pos[n];
    pos[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>vec[vec.size()-1]){
            vec.push_back(arr[i]);
            pos[i] = vec.size();
        }
        else{
            int a = lower_bound(all(vec), arr[i])-vec.begin();
            pos[i] = a+1;
            vec[a] = arr[i];
        }
    }
    cout<<vec.size()<<endl;
    int cnt = vec.size();
    vi ans;
    for (int i = n-1; i >=0; i--)
    {
        // cout<<pos[i];
        if(cnt==pos[i]){
            ans.push_back(arr[i]);
            cnt--;
        }
    }
    reverse(all(ans));
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
    
}