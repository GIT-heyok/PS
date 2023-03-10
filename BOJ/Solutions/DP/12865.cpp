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
const int INF = 1234567890;


int main(){
    FAST
    int n, k;
    cin >> n >>k;
    int memo[n][k+1];
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            memo[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a>>b;
        if(i==0){
            if(a<=k){
                memo[0][a] = b;
            }            
        }
        else{
            for(int j=0; j<=k; j++){
                memo[i][j] = memo[i-1][j];
            }
            for(int j=k; j>=0; j--){
                if(memo[i][j]!=0||j==0){
                    if(j+a<=k){
                        memo[i][j+a]=max(memo[i][j+a], memo[i][j]+b);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=k; i++){
        ans = max(ans, memo[n-1][i]);
    }
    cout<<ans<<endl;
}