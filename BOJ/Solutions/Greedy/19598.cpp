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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;

int main(){
    FAST
    string n;
    int k;
    cin >> n >> k;
    int sz = n.length();
    if(stoi(n)==1000000)cout<<1000000<<endl;
    else{
        if(k==0)cout<<n<<endl;
        else{
            if(stoi(n)<10){
                cout<<-1<<endl;
            }
            else if(stoi(n)<100&&stoi(n)%10==0){
                cout<<-1<<endl;
            }
            else{
                bool ans[1000000];
                for (int i = 0; i < 1000000; i++)
                {
                    ans[i] = false;
                }
                ans[stoi(n)]= true;
                for (int i = 0; i < k; i++)
                {
                    bool ans2[1000000];
                    for (int l = 0; l< 1000000; l++)
                    {
                        ans2[i] = false;
                    }
                    for (int l = 0; l < 1000000; l++)
                    {
                        if(ans[l]){
                            string temp = to_string(l);
                            for (int j = 0; j < sz; j++)
                            {
                                for (int tt = i+1; tt < sz; tt++)
                                {
                                    swap(temp[j], temp[tt]);
                                    ans2[stoi(temp)]=true;
                                    swap(temp[j], temp[tt]);
                                }
                                
                            }
                            
                        }
                    }
                    for (int l = 0; l < 1000000; l++)
                    {
                        ans[l] = ans2[l];
                    }
                    
                    
                }
                
                for (int i = 999999; i>=0; i--)
                {
                    if(ans[i]){cout<<i<<endl;break;}
                }
                         
            }
        }
    }
}