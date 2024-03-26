#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
vector<int> getZArray(string &s){
    vector<int> z(s.length());
    int l = 0, r = 0;
    z[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        if(i < r){
            z[i] = min(r-i,z[i-l]);
        }
        while(i+z[i]<s.length()&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r = i+z[i];
        }
    }
    return z;
}
typedef long long ll;

//only one different = front and back
int main(void) {
    FAST
    string s, revS, t, revT;
    cin >> revS >> revT;
    s = revS;
    t = revT;
    reverse(revS.begin(), revS.end());
    reverse(revT.begin(), revT.end());
    string sReal = t+"!"+s;
    string sRevReal = revT+"!"+revS;
    vector<int> z, zRev;
    z = getZArray(sReal);
    zRev = getZArray(sRevReal);
    /*
    for (int i = 0; i < sReal.length(); ++i) {
        cout<<sReal[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < z.size(); ++i) {
        cout<<z[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < sRevReal.length(); ++i) {
        cout<<sRevReal[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < z.size(); ++i) {
        cout<<zRev[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < z.size(); ++i) {
        cout<<i<<" ";
    }
    cout<<endl;
     */
    int cnt = 0;
    int tlen = t.length(), totlen = sReal.length();

    int idx = tlen+1;
    int revIdx = totlen-tlen;
    while(revIdx>tlen){
        if(z[idx]+zRev[revIdx]==tlen-1)cnt++;
        idx++;
        revIdx--;
    }
    cout<<cnt<<endl;
}
