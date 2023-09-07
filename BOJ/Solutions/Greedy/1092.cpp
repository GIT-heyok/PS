#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {    
    FAST
    int n;
    cin >> n;
    vector<int> cranes(n);
    int craneLoad[n];
    memset(craneLoad,0,sizeof(craneLoad));
    for (int i = 0; i < n; i++)
    {
        cin >> cranes[i];
    }
    sort(cranes.begin(), cranes.end());
    int m;
    cin >> m;
    vector<int> loads(m);
    for (int i = 0; i < m; i++)
    {
        cin >> loads[i];
    }
    sort(loads.begin(), loads.end());
    if(loads[m-1]>cranes[n-1]){ //no crane can carry the heaviest box
        cout<<-1<<endl;
    }
    else{
        int ptr = m-1;
        for (int i=n-1; i>0; i--)
        {
            while(ptr>=0&&loads[ptr]>cranes[i-1]){
                craneLoad[i]++;
                ptr--;       
            }
        }
        craneLoad[0] = ptr+1;/*
        for (int i = 0; i < n; i++)
        {
            cout<<craneLoad[i]<<" ";
        }
        cout<<endl;
        */
        ll ans = 0;
        ll temp = 0;
        int cnt = 0;
        for (int i = n-1; i >=0; i--)
        {
            cnt++;
            temp+=craneLoad[i];
            ans = max(ans,(temp+cnt-1)/cnt); 
        }
        
        cout<<ans<<endl;
    }
}