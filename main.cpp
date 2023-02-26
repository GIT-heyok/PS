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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const ll INF = 1234567890123LL;

array<ll, 3> extend_euclid(ll a, ll b) {
	// we know that (1 * a) + (0 * b) = a and (0 * a) + (1 * b) = b
	array<ll, 3> x = {1, 0, a};
	array<ll, 3> y = {0, 1, b};

	// run extended Euclidean algo
	while (y[2] > 0) {
		// keep subtracting multiple of one equation from the other
		ll k = x[2] / y[2];
		for (int i = 0; i < 3; i++) { x[i] -= k * y[i]; }
		swap(x, y);
	}
	return x;  // x[0] * a + x[1] * b = x[2], x[2] = gcd(a, b)
}
ll inv_general(ll a, ll b) {
	array<ll, 3> x = extend_euclid(a, b);
	return x[0] + (x[0] < 0) * b;
}
int main()
{
    FAST
    ll P, B, N;
    while((cin >> P >> B >> N)){
        ll arr[33];
        arr[0] = B%P;
        for (int i = 0; i<32; i++)
        {
            arr[i+1] = (arr[i]*arr[i])%P;
            
            // cout<<(1<<i)<<" : " <<arr[i]<<", ";
        }
        // cout<<endl;
        int mxK = 0;
        for (int i = 0; i <= 32; i++)
        {
            if((1LL<<i)>=P){
                mxK = i;
                break;
            }
        }
        bool flag = false;
        ll ans = 1234567890123LL;
        vector<pLL> temp;
        // cout<<mxK<<endl;
        for (int i = 0; i < (1<<(mxK/2)); i++)
        {
            ll curVal = 1;
            for (int j = 0; j < mxK; j++)
            {
                if(i&(1<<j)){
                    curVal *= arr[j];
                    curVal%=P;
                }   
            }
            // cout<<i<<" "<<curVal<<endl;
            if(curVal==N){
                flag = true;
                ans = i;
            }  
            else{
                temp.push_back({curVal, i});
            }
        }

        if(flag){
            cout<<ans<<endl;
        }
        else{
            sort(all(temp));
            // for(ll a: temp){
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            for (ll i = 1; i <( 1<<(mxK-(mxK/2))); i++)
            {
                ll curVal = 1;
                ll num = i<<(mxK/2);
                for (int j = mxK/2; j < mxK; j++)
                {
                    if(num&(1LL<<j)){
                        curVal *= arr[j];
                        curVal%=P;
                    }   
                }
                // cout<<curVal<< " "<<num<<endl;

                pLL aa = {(N*inv_general(curVal,P))%P,0LL};
                pLL bb = {(N*inv_general(curVal,P))%P,INF};
                int lb = lower_bound(all(temp), aa)-temp.begin();
                int ub = upper_bound(all(temp), bb)-temp.begin();
                if(ub>lb){
                    for (int i = lb; i < ub; i++)
                    {
                        // cout<<temp[i].second<<" "<<num<<" "<<temp[i].first<<" "<<curVal<<" "<<(temp[i].first*curVal)%P<<endl;
                        ans = min(ans, temp[i].second);
                        ans+=num;
                        flag = true;
                    }
                }
                if(flag)break;
               
            } 
            if(ans>=INF){
                cout<<"no solution"<<endl;
            }
            else{
                cout<<ans<<endl;
            }
        
        }
        

        
        
        
    }   
}