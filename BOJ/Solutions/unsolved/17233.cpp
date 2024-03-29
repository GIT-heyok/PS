#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
vector<pair<int, pair<int, int>>> allCollection;

int cnt[100];

// 접두사와 접미사 일치하는 최대 일치 길이 테이블 구하기
vector<int> makeTable(string& fs) { // fs : 검색할 문자열
    int fsSize = fs.size();
    vector<int>	table(fsSize, 0); // 0으로 초기화
    int j = 0;
    for (int i = 1; i < fsSize; i++) {
        // 일치하지 않으면
        while (j > 0 && fs[i] != fs[j]) {
            j = table[j - 1];
        }
        // 일치하면
        if (fs[i] == fs[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

// ws : 검색을 당하는 문자열, fs : 검색할 문자열
void KMP(string& ws, string& fs, int idx) {
//    vector<int> ans;
    vector<int> table = makeTable(fs);
    int wsSize = ws.size();
    int fsSize = fs.size();
    int j = 0;
    for (int i = 0; i < ws.size(); i++) {
        // 일치하지 않는 경우 (단, j > 0)
        while (j > 0 && ws[i] != fs[j]) {
            j = table[j - 1];
        }
        // 일치한 경우
        if (ws[i] == fs[j]) {
            if (j == fsSize - 1) { // 문자열이 완전히 일치하면
                allCollection.push_back({i-fsSize+1,{0,idx}}); //in
                allCollection.push_back({i,{1,idx}}); //out
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
}
int main(void) {
    FAST
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp >> arr[i];
    }
    int temp;
    string hay;
    cin >> temp >> hay;
    for (int i = 0; i < n; ++i) {
        KMP(hay, arr[i], i);
    }
    sort(allCollection.begin(), allCollection.end());
    cout<<allCollection.size()<<endl;
    for (int i = 0; i < allCollection.size(); ++i) {
        cout<<allCollection[i].first<<" "<<allCollection[i].second.first<<" "<<arr[allCollection[i].second.second]<<endl;
    }

    int l = 0, r = 0;
    for (int i = 0; i < allCollection.size(); ++i) {
        
    }


}
