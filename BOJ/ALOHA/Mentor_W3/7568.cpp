#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    FAST
    int n;
    cin >> n;
    int weight[n], height[n];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < n; ++i) {
        int k = 0; // 문제에서 제시된 그대로이다.
        for (int j = 0; j < n; ++j) {
            if(weight[i] < weight[j] && height[i] < height[j]){
                k++;
            }
        }
        cout << k+1 << " ";
    }
    cout << endl;
}
