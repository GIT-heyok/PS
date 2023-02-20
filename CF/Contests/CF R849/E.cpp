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

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vll vec(n);
        ll sum = 0;
        bool containsZero = false;
        int negCount = 0;
        ll negSum = 0, negMax=-INF, posmin = INF;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            sum+=vec[i];
            if(vec[i]==0){
                containsZero = true;
            }
            else if(vec[i]<0){
                negCount++;
                negSum+=vec[i];
                negMax = max(negMax, vec[i]);
            }
            else{
                posmin= min(posmin, vec[i]);
            }
        }

        if(containsZero){
            cout<<sum-2*negSum<<endl;
        }
        else{
            if(negCount%2==0){
                cout<<sum-2*(negSum)<<endl;
            }
            else{
                if(posmin>-negMax){
                    cout<<sum-2*negSum+2*negMax<<endl;
                }
                else{
                    cout<<sum-2*negSum-2*posmin<<endl;
                }
            }
        }
        // cout<<sum<<endl;
        
        
    }
}