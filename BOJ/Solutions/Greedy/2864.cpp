#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	string mnm1, mnm2, mxm1, mxm2;
	for (int i = 0; i < s1.length(); i++)
	{

		if(s1[i]=='6'){
			mnm1 += '5';
		}
		else{
			mnm1+=s1[i];
		}
		if(s1[i]=='5'){
			mxm1 += '6';
		}
		else{
			mxm1+=s1[i];
		}
	}
	
	for (int i = 0; i < s2.length(); i++)
	{

		if(s2[i]=='6'){
			mnm2 += '5';
		}
		else{
			mnm2+=s2[i];
		}
		if(s2[i]=='5'){
			mxm2 += '6';
		}
		else{
			mxm2+=s2[i];
		}
	}

	cout<<stoi(mnm1)+stoi(mnm2)<<" "<<stoi(mxm1)+stoi(mxm2)<<endl;
} 