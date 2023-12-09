#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int n, m;

vector<int> vec;
int arr[8];
bool chk[8];

void solve(int cnt){
    if(cnt==m){
        for (int i = 0; i < m; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int xx = 0;
    for (int i = 0; i < n; ++i) {
        if(!chk[i] && vec[i] != xx){
            arr[cnt] = vec[i];
            xx = arr[cnt];
            chk[i] = true;
            solve(cnt+1);
            chk[i] = false;

        }
    }
}

int main() {
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    solve(0);



}
