#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, k, d, w;
        cin >> n >> k >> d >>w;
        queue<int> q;
        int arr[n+1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        arr[n] = INF;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int curTime = arr[i];
            q.push(curTime+d);
            if(q.size()==k){
                // cout<<"!"<<curTime<<endl;
                ans++;
                for (int j = 0; j < k; j++)
                {
                    q.pop();
                }
            }
            if(q.size()!=0&&q.front()+w<arr[i+1]){
                // cout<<"?"<<curTime<<endl;
                ans++;
                int qs = q.size();
                for (int j = 0; j < qs; j++)
                {
                    q.pop();
                }
            }
        }
        cout<<ans<<endl;
        
        
    }
}