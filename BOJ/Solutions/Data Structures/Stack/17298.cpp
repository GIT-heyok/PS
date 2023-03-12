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
const int MAX = 10001;
const ll INF = 1e9;
int main()
{
    FAST 
    int n;
    cin >> n;
    int arr[n];
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    deque<int> d; // push_front, push_back, pop_front, pop_back, front, back
    for (int i = n - 1; i >= 0; i--)
    {
        if(d.empty()){
            ans[i] = -1;
        }
        else{
            while(!d.empty()&&d.front()<=arr[i]){
                d.pop_front();
            }
            if(d.empty())ans[i]=-1;
            else ans[i] = d.front();
        }
        d.push_front(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}
