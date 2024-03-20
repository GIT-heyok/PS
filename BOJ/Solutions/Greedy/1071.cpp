#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;


int cnt[1004];
int main(void) {
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        cnt[temp+1]++;
    }
//    for (int i = 0; i < 10; ++i) {
//        cout<<cnt[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 1; i <= 1001; ++i) {
        if(cnt[i]==0){
            continue;
        }
        else{
            if(cnt[i+1]==0){
                while(cnt[i]>0){
                    cnt[i]--;
                    n--;
                    cout<<i-1<<" ";
                }
                continue;
            }
            else{
                if(cnt[i]+cnt[i+1]==n){
                    while(cnt[i+1]>0){
                        cnt[i+1]--;
                        n--;
                        cout<<i<<" ";
                    }
                    while(cnt[i]>0){
                        cnt[i]--;
                        n--;
                        cout<<i-1<<" ";
                    }
                    break;
                }
                else{
//                    cout<<"!"<<endl;
                    while(cnt[i]>0){
                        cnt[i]--;
                        n--;
                        cout<<i-1<<" ";
                    }
                    for (int j = i+2; j <= 1002; ++j) {
                        if(cnt[j]>0){
                            n--;
                            cnt[j]--;
                            cout<<j-1<<" ";
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<endl;
}

