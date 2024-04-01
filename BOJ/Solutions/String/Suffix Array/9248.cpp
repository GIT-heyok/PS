#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
string s;
int n, d, sa[500000], pos[500000], lcp[500000];

bool cmp(int i, int j) {
    if (pos[i] != pos[j])return pos[i] < pos[j];
    i += d;
    j += d;
    if (i < n && j < n) {
        return pos[i] < pos[j];
    }
    return i > j;
}

void suffixArray() {
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        pos[i] = s[i];
    }
    d = 1;
    while (true) {
        sort(sa, sa + n, cmp);
        vector<int> temp(n);
        for (int i = 0; i < n - 1; ++i) {
            temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            pos[sa[i]] = temp[i];
        }
        if (temp[n - 1] == n - 1)break;
        d *= 2;
    }
}

void lcpArray() {
    for (int i = 0, k=0; i < n; i++, k=max(k-1,0)) {
       if(pos[i]==n-1)continue;

        for (int j = sa[pos[i]+1]; s[i+k]==s[j+k]; k++);

            lcp[pos[i]] = k;
    }
}

int main() {
    FAST
    cin >> s;
    n = s.length();
    suffixArray();
    lcpArray();
    for (int i = 0; i < n; ++i) {
        cout << sa[i] + 1 << " ";
    }
    cout << endl;
    cout<<"x ";
    for (int i = 0; i < n-1; ++i) {
        cout << lcp[i] << " ";
    }
    cout << endl;

}
