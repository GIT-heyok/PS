#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;

string s;
const int DIGIT = 28;
const int MXMSZ = 600'000;
ll MOD = 1e9+7;
vector<ll> hashes[MXMSZ];
ll hashStr[MXMSZ];
ll digPow[MXMSZ];
int getLen(int ba, int bb, int la, int lb){
    int start = min(ba, bb);
    int end = max(ba+la-1, bb+lb-1);
    return end-start+1;
}
ll getHash(int l, int r){
    return ((hashStr[r]-hashStr[l-1]*digPow[r-l+1])%MOD+MOD)%MOD;
}

ll getHashStr(string ss){
    int temp = 0;
    for (int i = 0; i < ss.length(); ++i) {
        temp*=DIGIT;
        temp += ss[i]-'a'+1;
    }
    return temp;
}
int main(void) {
    FAST
    cin >> s;
    digPow[0] = 1;
    for (int i = 0; i < MXMSZ-1; ++i) {
        digPow[i+1] = digPow[i]*DIGIT;
    }
    hashStr[0] = 0;
    for (int i = 1; i <= s.length(); ++i) {
        hashStr[i] = hashStr[i-1]*DIGIT;
        hashStr[i] += (s[i-1]-'a')+1;
        hashStr[i]%=MOD;
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j+i-1 <= s.length(); ++j) {

            hashes[getHash(j, j+i-1)].push_back(j);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        ll ha = getHashStr(a), hb = getHashStr(b);
        if(ha==hb){
            if(hashes[ha].empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<a.length()<<endl;
            }
        }
        else{
            if(hashes[ha].size()>hashes[hb].size()){
                swap(ha, hb);
                swap(a, b);
            }
            if(hashes[ha].empty()){
                cout<<-1<<endl;
            }
            else{
                int t1 = hashes[ha][0], t2 = hashes[hb][hashes[hb].size()-1];
                int lll = min(t1, t2);
                int rr = max(t1+a.length()-1, t2+b.length()-1);
                int mnm = rr-lll+1;
//                for (int j = 0; j < hashes[ha].size(); ++j) {
//                    cout<<hashes[ha][j]<<" ";
//                }
//                cout<<endl;
//                for (int j = 0; j < hashes[hb].size(); ++j) {
//                    cout<<hashes[hb][j]<<" ";
//                }
//                cout<<endl;
                for (int j = 0; j < hashes[ha].size(); ++j) {
                    int startIdx = hashes[ha][j] - max((int)(b.length() - a.length()), 0);
                    int starta = hashes[ha][j];
                    auto res = lower_bound(hashes[hb].begin(), hashes[hb].end(), startIdx);
                    if(res!=hashes[hb].end())
                        mnm = min(mnm, getLen(starta, *res, a.length(), b.length()));
                    if(res!=hashes[hb].begin()){
                        res--;
                        mnm = min(mnm, getLen(starta, *res, a.length(), b.length()));
                    }
                }
                cout<<mnm<<endl;

            }

        }
    }

}
