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
#include <numeric>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
int main(){
    FAST
    int n;
    cin >> n;
    int ans = 0;
    int arr[5] = {100,20,10,5,1};
    for (int i = 0; i < 5; i++)
    {
        ans+=n/arr[i];
        n-=n/arr[i]*arr[i];
    }
    cout<<ans<<endl;
    
}