#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int main() {
    FAST
    int n, s;
    cin >> n >> s;
    int lengthMin = n+1;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ptr1 = 0, ptr2 = -1;
    int sum = 0;
    while(ptr1<n){
        if(sum<s){
            ptr2++;
            if(ptr2==n)break;
            sum+=arr[ptr2];
            if(sum>=s){
                lengthMin = min(lengthMin, ptr2-ptr1+1);
            }
        }
        else{
            sum-=arr[ptr1];
            ptr1++;
            if(sum>=s){
                lengthMin = min(lengthMin, ptr2-ptr1+1);
            }
        }
    }
    if(lengthMin==n+1)cout<<0<<endl;
    else cout<<lengthMin<<endl;
}
