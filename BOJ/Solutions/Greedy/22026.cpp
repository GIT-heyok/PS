#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int n, k;
vector<int> hammingDistance[31];
int originalHamming=0;
int getHamming(int a, int b){
    return __builtin_popcount(a^b);
}
pair<int,int> chk[100001];
int idx[100001];

bool reversal(int N, int M, std::vector<std::string> P)
{
    for (int rm = 0; rm < M; ++rm) {
        for (int cm = 0; cm < M; ++cm) {
            //cout<<rm << " "<<cm<<endl;
            for (int r = rm; r < N; r+=M) {
                if(P[r][cm]=='O'){
                    for (int c = cm; c < N; c+=M) {
                       P[r][c] = P[r][c]=='X'?'O':'X';
                    }
                }
            }
            for (int c = cm; c < N; c+=M) {
                if(P[rm][c]=='O'){
                    for (int r = rm; r < N; r+=M) {
                        P[r][c] = P[r][c]=='X'?'O':'X';
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            //cout<<P[i][j];
            if(P[i][j]=='O')return false;
        }
        //cout<<endl;
    }
    return true;
}
int main() {
   FAST

    int n, m;
    cin >> n >> m;

    vector<string> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << reversal(n, m, p) << endl;

    return 0;
}