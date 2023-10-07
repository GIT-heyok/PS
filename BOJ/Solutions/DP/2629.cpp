#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    FAST
    bool knapsack[31][80001];
    memset(knapsack, 0, sizeof(knapsack));
    int base = 40000;
    knapsack[0][base] = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        for (int j = 0; j < 80001; ++j) {
           if(j-temp>=0&&knapsack[i][j])knapsack[i+1][j-temp] = true;
            if(j+temp<=80000&&knapsack[i][j])knapsack[i+1][j+temp] = true;
            if(knapsack[i][j])knapsack[i+1][j] = true;
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        if(knapsack[n][temp+base]||knapsack[n][base-temp])cout<<"Y ";
        else cout<<"N ";
    }
    cout<<endl;
}

