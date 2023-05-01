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
        int stones[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin >> stones[i];
        }
        ll subSum[n+1];
        subSum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            subSum[i]=subSum[i-1]+stones[i];
        }
        int start=1;
        int end=n;
        while(start<=end){
            if(start==end){cout<<"! "<<start<<endl;cout.flush(); break;}
            int mid = start+(end-start)/2;
            int cnt = mid-start+1;
            cout<<"? "<<cnt<<" ";
            for (int i = start; i <= mid; i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            cout.flush();
            ll expected = subSum[mid]-subSum[start-1];
            ll realVal;
            cin >>realVal;
            if(expected==realVal){
                start = mid+1;
            }
            else{
                end = mid;
            }
            
        }
        
    }
}