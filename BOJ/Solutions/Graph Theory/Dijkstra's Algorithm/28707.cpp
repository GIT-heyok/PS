#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
ll INF = 1e14;
int n;
int arrToHash(vector<int>& arr){
    int number = 0;
    for(int i=0; i<n; i++){
        number*=11;
        number+=arr[i];
    }
    return number;
}
vector<int> hashToArr(int hash){
    vector<int> ret;
    for(int i=0;i<n; i++){
        ret.push_back(hash%11);
        hash/=11;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int swap(int l, int r, int hash){

    vector<int> arr = hashToArr(hash);
    swap(arr[l],arr[r]);
    return arrToHash(arr);
}

map<int, int> dist;
priority_queue<pair<int, int>> pq;

int main() {
    FAST
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<pair<int,pair<int,int>>> graph;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a>> b>> c;
        graph.push_back({a-1,{b-1,c}});
    }
    dist[arrToHash(arr)] = 1;
    pq.push({-1,arrToHash(arr)});
    while(!pq.empty()){
        int curHash = pq.top().second;
        vector<int> curArr = hashToArr(curHash);
//        cout<<"CURARR"<<endl;
//        for (int i = 0; i < n; ++i) {
//            cout<<curArr[i]<<" ";
//        }
//        cout<<endl;
        int curVal = -pq.top().first;
//        cout<<curHash<<" "<<curVal<<" "<<dist[curHash]<<endl;
        pq.pop();
        if(dist[curHash]!=0&&dist[curHash]<curVal)
            continue;
        for(int i=0; i<graph.size(); i++){
            int a, b, c;
            a = graph[i].first;
            b = graph[i].second.first;
            c = graph[i].second.second;
//            cout<<a<<" "<<b<<" "<<c<<endl;
            if(curArr[a]!=curArr[b]){
                int nextHash = swap(a, b, curHash);
                int nextVal = curVal+c;
                if(dist[nextHash]==0){
                    dist[nextHash] = nextVal;
                    pq.push({-nextVal,nextHash});
                }
                else if(dist[nextHash]>nextVal){
                    dist[nextHash] = nextVal;
                    pq.push({-nextVal,nextHash});
                }
            }
        }
    }

    sort(arr.begin(), arr.end());
    int ansHash = dist[arrToHash(arr)];
    if(ansHash==0)
        cout<<-1<<endl;
    else
        cout<<ansHash-1<<endl;
}