#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
	int T;
	cin >> T;
	int arr[4] = {25,10,5,1};

	while(T--){
		int n;
		cin >> n;
		for (int i = 0; i < 4; i++)
		{
			cout<<n/arr[i]<<" ";
			n-=n/arr[i]*arr[i];
		}
		cout<<endl;
	}	
} 