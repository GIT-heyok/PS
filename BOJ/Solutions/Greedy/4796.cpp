#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {

	int l, v, p;
	int cnt = 1;
	while(true){
		cin >> l >> p >> v;
		if(l==0)break;
		cout<<"Case "<<cnt<<": "<<v/p*l+min(v%p,l)<<endl; 
		cnt++;
	}
} 