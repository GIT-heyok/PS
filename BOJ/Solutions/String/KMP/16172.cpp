#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 1501;
const ll INF = 1e9;

// 접두사와 접미사 일치하는 최대 일치 길이 테이블 구하기
vector<int> makeTable(string fs) { // fs : 검색할 문자열
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
bool KMP(string ws, string fs) { 
	bool found = false;
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
                found = true;
                j = table[j];
			}
			else {
				j++;
			}
		}
	}
    return found;
}

int main()
{
    FAST
    string s;
    cin >> s;
    string sParsed = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='0'&&s[i]<='9'){

        }
        else{
            sParsed+=s[i];
        }
    }
    string fs;
    cin >> fs;
    cout<< KMP(sParsed, fs)<<endl;
}
    

