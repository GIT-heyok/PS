#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
	//# of segments/2
	string s;
	cin >> s;
	char cur = ' ';
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if(cur!=s[i]){
			cnt++;
			cur = s[i];
		}
	}
	cout<<cnt/2<<endl;
	
} 