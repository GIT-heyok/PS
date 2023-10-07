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
    bool knapsack[31][40001];
    memset(knapsack, 0, sizeof(knapsack));
    knapsack[0][0] = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        for (int j = 0; j < 40001; ++j) {
            if(j-temp>=0&&knapsack[i][j-temp])knapsack[i+1][j-temp]=true;
            if(j+temp<=40000&&knapsack[i][j+temp])knapsack[i+1][j+temp]=true;
            if(knapsack[i][j])knapsack[i+1][j]=true;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        if(knapsack[n][temp])cout<<"Y ";
        if(knapsack[n][temp])cout<<"N ";
    }
    cout<<endl;
}

