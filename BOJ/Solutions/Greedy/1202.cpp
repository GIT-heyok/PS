#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;
const int MAX = 300001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int n, k;
int parent[MAX];
int find(int node){
    if(parent[node]>=k)return k;
    if(node==parent[node]){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);   
    }
}
int main()
{
    FAST
    cin >> n >> k;
    vector<pI> jewels(n); //one jewel : {Value, Weight}

    for (int i = 0; i < n; i++)
    {
        cin >> jewels[i].second >> jewels[i].first;
    }
    sort(all(jewels)); //sort by value;
    vector<int> bags(k);//one bag: weight, sort by weight
    for (int i = 0; i < k; i++)
    {
        cin >> bags[i];
    }
    sort(all(bags));
    for (int i = 0; i <= k; i++)
    {
        parent[i] = i; //pointer pointing to itself
    }
    
    ll ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int temp = jewels[i].second;
        int index = upper_bound(all(bags), temp-1)-bags.begin();
        cout<<index<<" "<<parent[index]<<" ";
        index = find(index);
        cout<<index<<endl;
        if(index!=-1){
            ans+=jewels[i].first;
            parent[index]++;
        }
    }
    
   for (int i = 0; i < k;i++)
   {
       cout<<parent[i]<<" ";
   }
   cout<<endl;
    
    cout<<ans<<endl;

    
    


}

