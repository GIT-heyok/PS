#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ptr = 0;
	int cnt = 1;
	while(ptr<s.length()){
		if(s[ptr]=='S'){
			ptr++;
		}
		else{
			ptr+=2;
		}
		cnt++;
	}
	cout<<min(cnt,n)<<endl;
}