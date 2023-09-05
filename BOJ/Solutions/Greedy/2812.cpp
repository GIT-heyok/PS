#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	queue<int> q[10];
	int n, k;
	cin >> n >> k;
	int origk = k;
	string num;
	cin >> num;
	for (int i = 0; i < n; i++)
	{
		q[num[i]-'0'].push(i);
	}
	vector<int> ans;
	int ptr = 0; //last selected number
	while(ptr<n){
		bool chk = false;
		for (int i = 9; i >= 0; i--)
		{
			while(!q[i].empty()&&q[i].front()<ptr)q[i].pop();
			if(!q[i].empty()&&q[i].front()-ptr<=k){
				ans.push_back(i);
				//cout<<i<<" "<<ans.size()<<n-origk<<endl;
				if(ans.size()==n-origk)chk=true;
				k-=(q[i].front()-ptr);
				//cout<<q[i].front()<<" "<<ptr<<" "<<i<<endl;
				ptr = q[i].front()+1;
				q[i].pop();
				break;
			}
		}
		if(chk)break;
	}
	for(int temp: ans)cout<<temp;
	cout<<endl;
}