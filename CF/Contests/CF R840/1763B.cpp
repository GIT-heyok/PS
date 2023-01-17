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
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> monster(n);
        int curDamage = k;
        //p, h 순으로 정렬해서 linear search를 진행합니다.
        for(int i=0; i<n; i++){
           cin >> monster[i].second; 
        }
         for(int i=0; i<n; i++){
           cin >> monster[i].first; 
        }
        int curIndex = 0;
        sort(all(monster));
        // for(auto s: monster){
        //     cout<<s.first<<" "<<s.second<<endl;
        // }
        while(k>=0&&curIndex<n){
            if(monster[curIndex].second<=curDamage){
                curIndex++;
            }
            else{
                k-=monster[curIndex].first;
                curDamage+=k;
            }
        }
        // cout<<k<<" "<<curIndex<<endl;
        if(curIndex==n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}