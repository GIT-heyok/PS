#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
int n;
int nthMoveBoard[11][20][20];
int globalMxm = 0;
//moves the from nthMoveBoard[depth]->nthMoveBoard[depth+1]
//direction 0: left 1: right 2: up 3: down
void moveBoard(int depth, int direction) {
    switch (direction) {
        case 0:
            for (int r = 0; r < n; ++r) {
                int recent = 0;
                int idx = 0;
                for (int c = 0; c < n; ++c) {
                    int cur = nthMoveBoard[depth][r][c];
                    if (cur > 0) {
                        if (recent != cur && recent > 0) {

                            nthMoveBoard[depth + 1][r][idx++] = recent;
                            recent = cur;
                        } else if (recent != cur && recent == 0) {
                            recent = cur;
                        } else {
                            nthMoveBoard[depth + 1][r][idx++] = cur + 1;
                            globalMxm = max(globalMxm, cur+1);
                            recent = 0;
                        }
                    }

                }
                nthMoveBoard[depth + 1][r][idx] = recent;
                for (int c = idx + 1; c < n; ++c) {
                    nthMoveBoard[depth + 1][r][c] = 0;
                }
            }
            break;
        case 1:
            for (int r = 0; r < n; ++r) {
                int recent = 0;
                int idx = n - 1;
                for (int c = n - 1; c >= 0; --c) {
                    int cur = nthMoveBoard[depth][r][c];
                    if (cur > 0) {
                        if (recent != cur && recent > 0) {

                            nthMoveBoard[depth + 1][r][idx--] = recent;
                            recent = cur;
                        } else if (recent != cur && recent == 0) {
                            recent = cur;
                        } else {
                            nthMoveBoard[depth + 1][r][idx--] = cur + 1;
                            globalMxm = max(globalMxm, cur+1);
                            recent = 0;
                        }
                    }

                }
                nthMoveBoard[depth + 1][r][idx] = recent;
                for (int c = idx - 1; c >= 0; --c) {
                    nthMoveBoard[depth + 1][r][c] = 0;
                }
            }
            break;
        case 2:
            for (int c = 0; c < n; ++c) {
                int recent = 0;
                int idx = 0;
                for (int r = 0; r < n; ++r) {
                    int cur = nthMoveBoard[depth][r][c];
                    if (cur > 0) {
                        if (recent != cur && recent > 0) {

                            nthMoveBoard[depth + 1][idx++][c] = recent;
                            recent = cur;
                        } else if (recent != cur && recent == 0) {
                            recent = cur;
                        } else {
                            nthMoveBoard[depth + 1][idx++][c] = cur + 1;
                            globalMxm = max(globalMxm, cur+1);
                            recent = 0;
                        }
                    }

                }
                nthMoveBoard[depth + 1][idx][c] = recent;
                for (int r = idx + 1; r < n; ++r) {
                    nthMoveBoard[depth + 1][r][c] = 0;
                }
            }
            break;
        case 3:
            for (int c = 0; c < n; ++c) {
                int recent = 0;
                int idx = n - 1;
                for (int r = n - 1; r >= 0; --r) {
                    int cur = nthMoveBoard[depth][r][c];
                    if (cur > 0) {
                        if (recent != cur && recent > 0) {

                            nthMoveBoard[depth + 1][idx--][c] = recent;
                            recent = cur;
                        } else if (recent != cur && recent == 0) {
                            recent = cur;
                        } else {
                            nthMoveBoard[depth + 1][idx--][c] = cur + 1;
                            globalMxm = max(globalMxm, cur+1);
                            recent = 0;
                        }
                    }

                }
                nthMoveBoard[depth + 1][idx][c] = recent;
                for (int r = idx - 1; r >= 0; --r) {
                    nthMoveBoard[depth + 1][r][c] = 0;
                }
            }
            break;
    }
}

int main(void) {
    FAST
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                int temp;
                cin >> temp;
                while (temp / 2) {
                    temp >>= 1;
                    cnt++;
                }
                nthMoveBoard[0][i][j] = cnt;
            }
        }
        switch (s[0]) {
            case 'l':
                moveBoard(0,0);
                break;
            case 'r':
                moveBoard(0,1);
                break;
            case 'u':
                moveBoard(0,2);
                break;
            case 'd':
                moveBoard(0,3);
                break;
        }
        cout<<"Case #"<<tc<<":"<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int n2 = nthMoveBoard[1][i][j];
                if(n2==0)cout<<0<<" ";
                else cout<< (1<<n2) << " ";
            }
            cout<<endl;
        }

    }
}
