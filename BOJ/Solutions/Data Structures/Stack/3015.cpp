#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF = 987654321;

int main() {    
    FAST
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    stack<pair<int,int>> st;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = vec[i];
        ll curCnt = 1;
        while(!st.empty()){
            int temp = st.top().first;
            int cnt = st.top().second;
            //cout<<temp<<"x"<<cnt<<" ";
            if(temp>vec[i]){
                ans++;
                break;
            }
            else if(temp==vec[i]){
                curCnt+=cnt;
                ans+=cnt;
                st.pop();   
            }
            else{
                st.pop();
                ans+=cnt;
            }
        }
        st.push({cur,curCnt});
        //cout<<" ans: "<<ans<<endl;
    }
    cout<<ans<<endl;
    
}