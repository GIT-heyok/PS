#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
vector<int> sizes;
int getCompressedIndex(int a) {
    return lower_bound(sizes.begin(), sizes.end(), a) - sizes.begin();
}
int main()
{
    FAST
    int n;
    cin >> n;
    sizes = vector<int>(n);
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        sizes[i] = vec[i];
    }
    sort(sizes.begin(), sizes.end());
    sizes.erase(unique(sizes.begin(),sizes.end()),sizes.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cout<<getCompressedIndex(vec[i])<<" ";
    }
    cout<<endl;
}
