#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int INF = 987654321;


ull objBoard=0;
int getBoard(ull& board, int r, int c){
   int idx = r*4+c;
   ull temp = board>>(4*idx);
   return temp%16;
}

void putBoard(ull* board, int r, int c, int val){
   int idx = r*4+c;
    //cout<<idx<<endl;
   ull temp = (*board>>(4*idx))%16;
   cout<<temp<<endl;
   *board-=temp<<(4*idx);
   *board+=(ull)val<<(4*idx);
  // cout<<*board<<endl;
}
int main() {    
   FAST
   int arr[4][4];
   for (int i = 0; i < 4; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         int temp;
         cin >> temp;
         putBoard(&objBoard,i,j,temp-1);
         cout<<objBoard<<endl;
      }
   }
   queue<     
}