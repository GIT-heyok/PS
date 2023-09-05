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
	vector<int> vec(n+1);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	vec[n] = 0;
	sort(vec.begin(), vec.end());
	int ptr = 0;
	int curSum =0;
	vec.push_back(1<<29);
	while(curSum+1>=vec[ptr+1]){
		curSum+=vec[ptr+1];
		ptr++;
	}
	cout<<curSum+1<<endl;
	

} 