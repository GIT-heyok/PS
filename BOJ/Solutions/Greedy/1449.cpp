#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
	int n, l;
	cin >> n >> l;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	auto ptr = vec.begin();
	int cnt = 0;
	int current = -(1<<29);
	while(ptr!=vec.end()){
		if(*ptr-current>=l){
			cnt++;
			current = *ptr;
		}
		ptr++;
	}
	cout<<cnt<<endl;
} 