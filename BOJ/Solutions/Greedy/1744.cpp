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
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	int ptr1 = 0;
	int ptr2 = vec.size()-1;
	while(ptr1<ptr2){
		if(vec[ptr1]*vec[ptr1+1]>=vec[ptr2]*vec[ptr2-1]){
			if(vec[ptr1]*vec[ptr1+1]>vec[ptr1]+vec[ptr1+1]){
				ans+=vec[ptr1]*vec[ptr1+1];
				ptr1+=2;
			}
			else{
				ans+=vec[ptr1];
				ptr1++;
			}
		}
		else{
			if(vec[ptr2]*vec[ptr2-1]>vec[ptr2]+vec[ptr2-1]){
				ans+=vec[ptr2]*vec[ptr2-1];
				ptr2-=2;
			}
			else{
				ans+=vec[ptr2];
				ptr2--;
			}
		}
	}
	if(ptr1==ptr2)ans+=vec[ptr1];
	cout<<ans<<endl;
} 