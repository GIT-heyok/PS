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
    int arr[3*n][n+1];
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            arr[i][j] = 1000;
        }
    }
    arr[1][0] = 0;
    queue<pair<int, int>> q;
    q.push({1,0});
    int ans = 100000;
    while(!q.empty()){

        int curN = q.front().first;
        int curClip = q.front().second;
       // cout<<curN<<" "<<curClip<<" "<<arr[curN][curClip]<<endl;
        q.pop();
        if(curN==n){cout<<arr[curN][curClip]<<endl;
            break;}
        if(curN>n){
            ans = min(ans, curN-n+arr[curN][curClip]);
            continue;
        }
        if(arr[curN][curN] > arr[curN][curClip]+1){
            q.push({curN, curN});
            arr[curN][curN] =arr[curN][curClip]+1;
        }
        if(arr[curN+curClip][curClip] > arr[curN][curClip]+1){
            q.push({curN+curClip, curClip});
            arr[curN+curClip][curClip] =arr[curN][curClip]+1;
        }
        if(curN-1>0&&arr[curN-1][curClip]>arr[curN][curClip]+1){
            q.push({curN-1, curClip});
            arr[curN-1][curClip] = arr[curN][curClip]+1;
        }
    }

}

