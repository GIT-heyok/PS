#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	/*
	N = 1 -> 1
	N = 2 -> 1~2: 1, 3~4:2, 5~6:3, 7+: 4
	N = 3+ -> 1~4: M, 5~6:4, 7:5, 8+: M-2 
	*/

	int n, m;
	cin >> n >> m;
	if(n==1)cout<<1<<endl;
	else if(n==2){
		if(m==1||m==2){
			cout<<1<<endl;
		}
		else if(m==3||m==4)cout<<2<<endl;
		else if(m==5||m==6)cout<<3<<endl;
		else cout<<4<<endl;
	}
	else{
		if(m<=4)cout<<m<<endl;
		else if(m<=6)cout<<4<<endl;
		else if(m<=7)cout<<5<<endl;
		else cout<<m-2<<endl;
	}
}