#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	int memo[100001];
	int n;
	cin >> n;
	for (int i = 0; i <= 100000; i++)
	{
		memo[i] = (1<<29);
	}
	memo[0] = 0;
	for (int i = 2; i <= 100000; i++)
	{
		memo[i] = min(memo[i-2]+1, memo[i]);
	}
	for (int i = 5; i <= 100000; i++)
	{
		memo[i] = min(memo[i-5]+1, memo[i]);
	}
	if(memo[n]>=(1<<29))cout<<-1<<endl;
	else cout<<memo[n]<<endl;
	
} 