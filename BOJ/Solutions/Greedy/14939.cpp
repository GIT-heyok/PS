#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

char arr[12][12];
char tempArr[12][12];

void toggleOneCell(int r, int c) {
    if (tempArr[r][c] == 'O')
        tempArr[r][c] = '#';
    else tempArr[r][c] = 'O';
}

void toggle(int r, int c) {
    toggleOneCell(r-1, c);
    toggleOneCell(r, c - 1);
    toggleOneCell(r, c);
    toggleOneCell(r, c + 1);
    toggleOneCell(r + 1, c);
}

int main() {
    FAST
    for (int i = 1; i <= 10; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= 10; ++j) {
            arr[i][j] = s[j-1];
        }
    }
    int mnm = 101;

    for (int i = 0; i < (1 << 10); ++i) {
        for (int j = 1; j <= 10; ++j) {
            for (int k = 1; k <= 10; ++k) {
                tempArr[j][k] = arr[j][k];
            }
        }
        int cnt = 0;
        for (int bit = 0; bit < 10; ++bit) {
            if (i & (1 << bit)) {
                toggle(1, 1 + bit);
                cnt++;
            }
        }
        for (int j = 2; j <= 10; ++j) {
            for (int k = 1; k <= 10; ++k) {
                if (tempArr[j - 1][k] == 'O') {
                    toggle(j, k);
                    cnt++;
                }
            }
        }
        for (int j = 1; j <= 10; ++j) {
            for (int k = 1; k <= 10; ++k) {
                if(tempArr[j][k]=='O'){
                    cnt = 101;
                }
            }
        }
        if(mnm>cnt){
            mnm = cnt;
        }
    }
    if(mnm==101)
        cout << -1 << endl;
    else cout<< mnm << endl;

}
