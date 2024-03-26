#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;
vector<pair<int, int>> edges[20];
int n;
int maxDiameter = 0;
int getDiameter(int i){
    int sum = 0;
    int largest = 0, secondLargest = 0;
    for (int j = 0; j < edges[i].size(); ++j) {
        pair<int, int> nxtNode = edges[i][j];
        int weight = nxtNode.second+ getDiameter(nxtNode.first);
//        cout<<weight<<" "<<i<<endl;
        if(weight>largest){
            secondLargest = largest;
            largest = weight;
        }
        else if(weight>secondLargest){
            secondLargest =weight;
        }
    }
    maxDiameter = max(maxDiameter, largest+secondLargest);
    return largest;
}
int main(void) {
    FAST
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
    }
    getDiameter(1);
    cout<<maxDiameter<<endl;

}

