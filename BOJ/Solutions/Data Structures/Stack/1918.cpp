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
const int MAX = 501;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;


vector<string> noMulSolve(vector<string> s){
	stack<string> st;
	for (int i = 0; i < s.size(); i++)
	{
		string temp = s[i];
		if(temp=="+"||temp=="-"){
			string nextTemp = s[++i];
			nextTemp = st.top()+nextTemp+temp;
			st.pop();
			st.push(nextTemp);
		}
		else{
			st.push(temp);
		}
	}
	vector<string> temp2;
	while(!st.empty()){
		temp2.push_back(st.top());
		st.pop();
	}	
	reverse(all(temp2));
	return temp2;
	
}

vector<string> noParsolve(vector<string> s){
	stack<string> st;
	for (int i = 0; i < s.size(); i++)
	{
		string temp=s[i];
		if(temp=="*"||temp=="/"){
			string nextTemp = "";
			nextTemp+=s[++i];
			nextTemp = st.top()+nextTemp+temp;
			st.pop();
			st.push(nextTemp);
		}
		else{
			st.push(temp);
		}
	}
	vector<string> temp2;
	while(!st.empty()){
		temp2.push_back(st.top());
		st.pop();
	}	
	reverse(all(temp2));
	return temp2;
	
}
vector<string> parSolve(vector<string> s){
	stack<string> st;
	for (int i = 0; i < s.size(); i++)
	{
		string temp="";
		temp+=s[i];
		if(temp==")"){
			vector<string> temps;
			while(st.top()!="("){
				temps.push_back(st.top());
				st.pop();
			}
			st.pop();
			reverse(all(temps));
			vector<string> temps2 = noMulSolve(noParsolve(temps));
			string ss = "";
			for (int i = 0; i < temps2.size(); i++)
			{
				ss+=temps2[i];
			}
			st.push(ss);
		}
		else{
			st.push(temp);
		}
	}
	vector<string> temp2;
	while(!st.empty()){
		temp2.push_back(st.top());
		st.pop();
	}
	reverse(all(temp2));	
	return temp2;
	
}


/*used stack<string> to maintain an already solved problem,
vector<string> to export it
parsolve: solving the inner-parenthesis stuff and appends it to
the vector<string>
noParsolve: solving the multiplication parts and appends it as a
chunk
noMulsolve: last step, addition part
*/

int main(){
    FAST
	string s;
	cin >> s;
	vector<string> vec(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		vec[i]+=s[i];
	}
	vector<string> vec2 = noMulSolve(noParsolve(parSolve(vec)));
	for (int i = 0; i < vec2.size(); i++)
	{
		cout<<vec2[i]<<" ";
	}

	cout<<endl;
		


}


