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
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int mxm = arr[n-1];
	int ans = 0;
	for (int i = n-2; i >= 0; i--)

	{
		if(mxm-1>=arr[i]){
			mxm = arr[i];
		}
		else{
			ans+=arr[i]-(mxm-1);
			mxm--;
		}
	}
	cout<<ans<<endl;
	
	
} 