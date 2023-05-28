#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const ll INF = 1234567890ll;
const ll MOD = 998244353;
const int inf = 1<<20;
int main(){
    FAST
        int k;
        cin >> k;
        int arr[(1<<k)];
        for (int i = 0; i < (1<<k); i++)
        {
            cin >> arr[i];
        }
        ll ans = 1;

        for (int i = 1; i <= k; i++)
        {
            ll cnt = 0;
            for (int j = 0; j < (1<<(k-i)); j++)
            {
                int duplicates = 0;
                int empty = -1;
                bool twoEmpty = false;
                for (int aa = 0; aa < (1<<i); aa++)
                {
                    int curIdx = j*(1<<i)+aa;
                    // cout<<arr[curIdx]<<endl;

                    if(arr[curIdx]==-1){
                        if(empty!=-1)twoEmpty = true;
                        empty=curIdx;
                    }
                    else if(arr[curIdx]>(1<<(k-i))&&arr[curIdx]<=(1<<(k-i+1))){
                        duplicates++;
                    }
                }
                // cout<<cnt<<" "<<duplicates<<" "<<empty<<" "<<twoEmpty<<" "<<ans<<endl;
                if(duplicates>1)ans*=0;
                if(empty>-1){
                    if(duplicates==1){

                    }
                    else{
                        cnt++;
                        arr[empty] = inf;
                        ans*=cnt;
                        ans%=MOD;
                    }
                }            
                if(twoEmpty){
                    ans*=2;
                    ans%=MOD;
                }    
                if(empty==-1&&duplicates==0)ans*=0;
            }
            
        }
        cout<<ans<<endl;
        
        
}