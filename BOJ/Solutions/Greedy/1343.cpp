#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	string board;
	cin >> board;
	int ptr = 0;
	int sz = board.length();
	bool chk = true;
	while(ptr<sz){
		if(board[ptr]=='.'){ptr++; continue;}
		bool chk1 = true;
		if(ptr+4<=sz){
			for (int i = 0; i < 4; i++)
			{
				if(board[ptr+i]=='.')chk1 = false;
			}
		}
		else{
			chk1 = false;
		}

		if(chk1){
			for (int i = 0; i < 4; i++)
			{
				board[ptr+i] = 'A';
			}
			ptr+=4;
		}
		else{
			if(ptr+2<=sz){
				for (int i = 0; i < 2; i++)
				{
					if(board[ptr+i]=='.')chk = false;
				}
			}
			else{
				chk = false;
			}

			if(chk){
				
				for (int i = 0; i < 2; i++)
				{
					board[ptr+i] = 'B';
				}
				ptr+=2;
			}
			else break;
		}
		
	}
	if(chk)cout<<board<<endl;
	else cout<<-1<<endl;
} 