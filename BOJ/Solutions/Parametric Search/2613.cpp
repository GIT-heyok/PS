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
typedef pair<double, double> pD;

const int MAX = 101;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;
int n, m, mx=0;
vector<int> vec;
vector<int> ansR;
int solve(){
    vector<int> ans;
    int l=mx, r=30000;
    int temp_ans = r;
    // vector<int> ans;
    while(l<=r){
        ans.clear();
        int mid = (l+r)/2;
        vector<int> temp;
        int cur = vec[0], cnt=1;
        
        for (int i = 1; i < n; i++)
        {
            if(cur+vec[i]>mid){
                ans.push_back(cnt);
                cnt = 1;
                cur = vec[i];
            }
            else{
                cnt++;
                cur+=vec[i];
            }
        }
        ans.push_back(cnt);
        if(ans.size()>m){
            l = mid+1;
        }
        else{
            if(temp_ans>mid){
                temp_ans = mid;
                ansR.clear();
                int cnt = m-ans.size();
                for (int a: ans)
                {
                    int temp = a;
                    while(temp>1&&cnt>0){
                        temp--;
                        cnt--;
                        ansR.push_back(1);
                    }
                    ansR.push_back(temp);
                }
            }
            
            r = mid-1;
        }
    }
    return temp_ans;
}
int main()
{
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        mx = max(mx, temp);
    }
    cout<<solve()<<endl;
    for (int a: ansR)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    
}
    
