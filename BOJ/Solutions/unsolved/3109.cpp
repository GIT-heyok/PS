#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	int r, c;
	cin >> r >> c;
	bool isWall[r][c];
	bool bottleNeck[r][c];
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			isWall[i][j] = s[j]=='x';
			bottleNeck[i][j] = j==0;
		}
	}
	
	for (int column = 1; column < c; column++)
	{
		for (int row = 0; row < r; row++)
		{
			if(row-1>=0&&!isWall[row-1][column])
				bottleNeck[row-1][column] |= bottleNeck[row][column-1];
			if(row+1<r&&!isWall[row+1][column])
				bottleNeck[row+1][column] |= bottleNeck[row][column-1];
			if(!isWall[row][column])
				bottleNeck[row][column] |= bottleNeck[row][column-1];
		}
		
	}
	int cnt = 1<<29;
	for (int column = 0; column < c; column++)
	{
		int cnt2 = 0;
		for (int row = 0; row < r; row++)
		{
			cnt2+=bottleNeck[row][column];
			//cout<<bottleNeck[row][column];
		}
		//cout<<endl;
		cnt = min(cnt,cnt2);
	}
	cout<<cnt<<endl;
	
	
}