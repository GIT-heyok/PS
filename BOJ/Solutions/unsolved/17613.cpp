#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>

#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
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
const int INF = 123456780;

int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >>b;
        int ans = 0;
        int arr[32];
        arr[1] = 1;
        for (int i = 1; i < 32; i++)
        {
          arr[i+1] = arr[i]*2+1;  
        }        
        
        while (a>0)
        {
            int temp = 0;
            for (int i = 1; i < 32; i++)
            {
                if(arr[i]>=a){
                    if(arr[i]<=b){
                        a=0;
                    }
                    temp = arr[--i];
                    a-=temp;
                    b-=temp;
                    ans += i;
                    break;
                }   
            }
            
        }
        cout<<ans<<endl;
        
        
    }
     
}