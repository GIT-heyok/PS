#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main(){
    FAST
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int l = 0;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        while(m<=sum){
            if(m==sum){
                cnt++;
            }
            sum-=arr[l];
            l++;
        }
    }
    cout<<cnt<<endl;
}
