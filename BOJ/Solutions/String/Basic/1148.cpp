#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int dict[200001][26];
int n = 0;
int main()
{
    FAST
    string s;
    cin >> s;
    while(s!="-"){
        for (int i = 0; i < s.length(); ++i) {
            dict[n][s[i]-'A']++;
        }
        n++;
        cin >> s;
    }
    string puzzle;
    cin >> puzzle;
    while(puzzle!="#"){
        int puz[26];
        for (int i = 0; i < 26; ++i) {
            puz[i] = 0;
        }
        for (int i = 0; i < puzzle.length(); ++i) {
            puz[puzzle[i]-'A']++;
        }
        int mnm=1e9, mxm=-1;
        string mns, mxs;
        for (int i = 0; i < 26; ++i) {
            int ansCnt = 0;
            if(puz[i]>0){
                for (int j = 0; j < n; ++j) {
                    bool chk = true;
                    if(dict[j][i]<=0){
                        continue;
                    }
                    dict[j][i]--;
                    puz[i]--;
                    for (int k = 0; k < 26; ++k) {
                        if(puz[k]<dict[j][k]) {
                            chk = false;
                            break;
                        }
                    }
                    dict[j][i]++;
                    puz[i]++;
                    ansCnt+=chk;
                }
                if(mnm>ansCnt){
                    mnm = ansCnt;
                    mns = (char)('A'+i);
                }
                else if(mnm==ansCnt){
                    mns += (char)('A'+i);
                }

                if(mxm<ansCnt){
                    mxm = ansCnt;
                    mxs = (char)('A'+i);
                }
                else if(mxm==ansCnt){
                    mxs += (char)('A'+i);
                }
            }
        }
        cout<<mns<<" "<<mnm<<" "<<mxs<<" "<<mxm<<endl;
        cin >> puzzle;

    }
}
