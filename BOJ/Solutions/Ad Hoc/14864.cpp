#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int arr1[100001], arr2[100001];
bool visited[100001];
int main(){
    FAST
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        arr1[b]++;
        arr2[a]++;
    }
    for (int i = 1; i <= n; ++i) {
        arr1[i] = i-1-arr1[i];
    }
    bool chk = true;
    for (int i = 1; i <= n; ++i) {
        int val = arr1[i]+arr2[i];
        if(val+1>n){
            chk = false;
            break;
        }
        if(visited[val+1]){
            chk = false;
            break;
        }
        visited[val+1] = true;
    }
    if(!chk)cout<<-1<<endl;
    else{
        for (int i = 1; i <= n; ++i) {
            cout<<arr1[i]+arr2[i]+1<<" ";
        }
        cout<<endl;
    }

}