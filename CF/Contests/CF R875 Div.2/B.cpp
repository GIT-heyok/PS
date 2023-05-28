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
        map<int, int> m1, m2;
        int prev = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;           
            if(temp==prev){
                cnt++;
            }
            else{
                if(m1[prev]<cnt){
                    m1[prev]=cnt;
                }
                    prev = temp;
                    cnt = 1;
            }
        }
        if(m1[prev]<cnt)m1[prev]=cnt;

        prev = -1;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;           
            if(temp==prev){
                cnt++;
            }
            else{
                if(m2[prev]<cnt){
                    m2[prev]=cnt;
                }
                
                    prev = temp;
                    cnt = 1;
            }
        }
        if(m2[prev]<cnt)m2[prev]=cnt;
        int ans = 0;
        for (auto i = m1.begin(); i!=m1.end() ; i++)
        {
            int curVal = i->first;
            ans = max(ans,m1[curVal]+m2[curVal]);       
        }
        
        for (auto i = m2.begin(); i!=m2.end() ; i++)
        {
            int curVal = i->first;
            ans = max(ans,m1[curVal]+m2[curVal]);       
        }
        cout<<ans<<endl;
        
    }
}