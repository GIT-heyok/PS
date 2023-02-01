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
        vi vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }
        sort(all(vec));
        int index = 0;
        int ans = 0;
        while(index<n){
            int a = upper_bound(all(vec), vec[index])-lower_bound(all(vec), vec[index]);//vec[i]의 개수 
            int b = upper_bound(all(vec), vec[index]+1)-lower_bound(all(vec), vec[index]+1);//vec[i]의 개수 
            index+=a;
            ans += max(a-b, 0);

        }
        cout<<ans<<endl;
    }
}