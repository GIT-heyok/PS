#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int arr[26];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < s.length(); i++)
	{
		arr[s[i]-'A']++;
	}
	int oddCnt = 0;
	for (int i = 0; i < 26; i++)
	{
		oddCnt+=arr[i]%2;
	}
	if(oddCnt>1){
		cout<<"I'm Sorry Hansoo"<<endl;
	}
	else{
		string orig, rev, middle;
		for (int i = 0; i < 26; i++)
		{
			while(arr[i]>=2){
				orig+=(char)(i+'A');
				arr[i]-=2;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if(arr[i])middle+=(char)(i+'A');
		}
		rev = orig;
		reverse(orig.begin(), orig.end());	
		cout<<rev+middle+orig<<endl;
	}
	
	
} 