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
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;


int main(){
	int T;
	cin >> T;
	while(T--){
		string s;
		int n;
		cin >> s >> n;
		deque<int> arr;
		string inp;
		cin >> inp;
		int val = 0;
		for (int i = 1; i < inp.length(); i++)
		{
			if(inp[i]>='0'&&inp[i]<='9'){
				val*=10;
				val+=(inp[i]-'0');
			}
			else{
				if(val!=0)
				arr.push_back(val);
				val = 0;
			}
		}

		bool hasError = false;
		vector<int> ans;
		bool fromFront = true;
		for (int i = 0; i < s.length(); i++)
		{
			if(s[i]=='R'){
				fromFront = !fromFront;
			}
			else{
				if(!arr.empty()){
					if(fromFront){
						arr.pop_front();
					}					
					else{
						arr.pop_back();
					}
				}
				else{
					hasError = true;
					break;
				}
			}
		}

		if(hasError){
			cout<<"error"<<endl;
		}
		else{
			cout<<'[';
			if(fromFront){
				while(!arr.empty()){
					cout<<arr.front();
					if(arr.size()>1){
						cout<<",";
					}
					arr.pop_front();
				}
			}
			else{
				while(!arr.empty()){
					cout<<arr.back();
					if(arr.size()>1){
						cout<<",";
					}
					arr.pop_back();
				}
			}
			cout<<']'<<endl;
			
		}
		
		
	}
}

