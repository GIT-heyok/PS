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
    int arr[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    if(n==1){
        int sum = 0;
        int mxm = 0;
        for (int i = 0; i < 6; i++)
        {
            sum+=arr[i];
            mxm = max(mxm, arr[i]);
        }
        sum-=mxm;
        cout<<sum<<endl;
        
    }
    else{
        int twos[12] = {0b000011, 0b000101, 0b001001,0b010001,
                    0b000110, 0b001010, 0b100010,
                    0b010100, 0b100100,
                    0b011000, 0b101000,
                    0b110000}; 

        int threes[8] =   {0b111000, 0b110100, 0b101010, 0b100110,
                        0b011001, 0b010101,
                        0b001011, 0b000111};
        ll oneMnm = (1<<29), twoMnm = (1<<29), threeMnm = (1<<29);
        for (int i = 0; i < 6; i++)
        {
            oneMnm = min(oneMnm, (ll)arr[i]);
        }

        for (int i = 0; i < 12; i++)
        {
            int bit = twos[i];
            ll cur = 0;
            for (int j = 0; j < 6; j++)
            {
                if(bit&(1<<j)){
                    cur += arr[j];
                }
            }
            twoMnm = min(twoMnm, cur);
            
        }
        
        for (int i = 0; i < 8; i++)
        {
            int bit = threes[i];
            ll cur = 0;
            for (int j = 0; j < 6; j++)
            {
                if(bit&(1<<j)){
                    cur += arr[j];
                }
            }
            threeMnm = min(threeMnm, cur);
            
        }
        cout<<oneMnm*(n-2)*(5*n-6)+twoMnm*(8*n-12)+threeMnm*4<<endl;
    }
}