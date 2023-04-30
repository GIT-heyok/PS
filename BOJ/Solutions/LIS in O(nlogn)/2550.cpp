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
LIS with encoding, decoding 
*/
int main()
{
    FAST;
    int n;
    cin >> n;
    int orig[n+1];
    int output[n+1];
    vector<int> vec;
    
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        orig[temp] = i;
        output[i] = temp;
    }
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = orig[temp];
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
    vector<int> anss;
    for (int i = 0; i < ans.size(); i++)
    {
        anss.push_back(output[ans[i]]);
    }
    sort(all(anss));
    for (int i = 0; i < anss.size(); i++)
    {
        cout<<anss[i]<<" ";   
    }
    
    
    
    cout<<endl;
    
}