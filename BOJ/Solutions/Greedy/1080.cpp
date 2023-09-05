#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[n][m], arr2[n][m];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr1[i][j] = s[j]-'0';
		}
		
	}
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr2[i][j] = s[j]-'0';
		}
		
	}

	int cnt = 0;
	for (int i = 0; i+3 <=n; i++)
	{
		for (int j = 0; j+3 <= m; j++)
		{
			if(arr1[i][j]!=arr2[i][j]){
				cnt++;
				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						arr1[i+r][j+c] = !arr1[i+r][j+c];
					}
				}
				
			}
		}
	}
	
	bool chk = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr1[i][j]!=arr2[i][j])chk=0;
		}
	}
	if(chk)cout<<cnt<<endl;
	else cout<<-1<<endl;
	
} 