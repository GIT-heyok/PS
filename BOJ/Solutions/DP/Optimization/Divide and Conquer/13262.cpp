#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 1000;
const int INF = 987654321;
ll preCalc[5000][5000];
vector<ll> dp_before(5000), dp_after(5000);
ll calculate(int l, int r){
    return preCalc[l][r];
    
}

void compute(int l, int r, int optl, int optr){
    if(l>r)return;

    int mid = (l+r)/2;
    pair<long long, int> best = {0, -1};
        for(int k=optl; k<=min(mid, optr); k++){
        best = max(best, {(k ? dp_before[k - 1] : 0) + calculate(k, mid), k});
    }
    dp_after[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main() {    
    FAST
    int n, k;
    cin >> n >> k;
    ll group[n];
    for (int i = 0; i < n; i++)
    {
        cin >> group[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll cost = 0;
        for (int j = i; j < n; j++)
        {
            cost|=group[j];
            preCalc[i][j] = cost;
        }
        
    }
    
    

    for (int i = 0; i < n; i++)
    {
        dp_before[i] = calculate(0,i);
    }
    for (int i = 1; i < k; i++)
    {
    compute(0,n-1,0,n-1);
    dp_before = dp_after;
    }
    cout<<dp_before[n-1];
    
     

}