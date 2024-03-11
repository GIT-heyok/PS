#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
int main(void) {
    FAST
    int arr[9];
    while(cin >> arr[0]){
        for (int i = 1; i < 9; ++i) {
            cin >> arr[i];
        }
        bool notFirstTerm = false;
        for (int i = 8; i >= 1; --i) {
            int coefficient = arr[8-i];
            if(coefficient==0)continue;
            if(notFirstTerm){
                if(coefficient<0){
                    cout<<"- ";
                }
                else{
                    cout<<"+ ";
                }
            }
            else{
                if(coefficient<0){
                    cout<<"-";
                }
            }
            if(abs(coefficient)!=1){
                cout<<abs(coefficient);
            }
            if(i!=1)
                cout<<"x^"<<i<<" ";
            else
                cout<<"x ";
            notFirstTerm = true;
        }
        if(arr[8]!=0){
            if(notFirstTerm){
                if(arr[8]<0){
                    cout<<"- ";
                }
                else{
                    cout<<"+ ";
                }
            }
            else{
                if(arr[8]<0){
                    cout<<"-";
                }
            }
            cout<<abs(arr[8])<<endl;
        }
        else{
            if(!notFirstTerm)cout<<0<<endl;
        }

    }

}
