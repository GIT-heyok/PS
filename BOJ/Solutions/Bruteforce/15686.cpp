#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int n, m, cntt;
bool chk[13];
int mnm = 1e9;

void solve(int idx, int cnt){
    if(cnt==cntt){
        int temp = 0;
//        for (int i = 0; i < chicken.size(); ++i) {
//            cout<<chk[i]<<" ";
//        }
//        cout<<endl;
        if(m>chicken.size()-m){
            for (int i = 0; i < house.size(); ++i) {
                    int ttemp = 1e9;
                    for (int j = 0; j < chicken.size(); ++j) {
                        if(!chk[j]) {
                            ttemp = min(ttemp, abs(chicken[j].first - house[i].first) +
                                               abs(chicken[j].second - house[i].second));
                        }
                    }
                    temp+=ttemp;
                }
        }
        else{
            for (int i = 0; i < house.size(); ++i) {
                    int ttemp = 1e9;
                    for (int j = 0; j < chicken.size(); ++j) {
                        if(chk[j]) {
                            ttemp = min(ttemp, abs(chicken[j].first - house[i].first) +
                                               abs(chicken[j].second - house[i].second));
                        }
                    }
//                    cout<<ttemp<<endl;
                    temp+=ttemp;
            }

        }
        mnm = min(temp, mnm);
        return;
    }
    if(idx==chicken.size())return;
    chk[idx] = true;
    solve(idx+1, cnt+1);
    chk[idx] = false;
    solve(idx+1, cnt);
}
int main() {
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            if(temp==1){
                house.push_back({i,j});
            }
            else if(temp==2){
                chicken.push_back({i,j});
            }
        }
    }
//    for (int i = 0; i < house.size(); ++i) {
//        cout<<house[i].first<<" "<<house[i].second<<", ";
//    }
//    cout<<endl;
//    for (int i = 0; i < chicken.size(); ++i) {
//        cout<<chicken[i].first<<" "<<chicken[i].second<<", ";
//    }
//    cout<<endl;
    if(m>chicken.size()-m){
        cntt = chicken.size()-m;
    }
    else{
        cntt = m;
    }
    solve(0,0);
    cout<<mnm<<endl;

}
