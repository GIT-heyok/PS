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
#include <memory.h>

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
typedef pair<double, double> pD;
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

bool isPossible[1000];
void checkStrike(int a, int b, int &strike, int &ball)
{
    bool visited[3] = {false, false, false};
    string s1 = to_string(a);
    string s2 = to_string(b);
    strike = 0;
    ball = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s1[i] == s2[i])
        {
            visited[i] = true;
            strike++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            if (s1[i] == s2[j] && !visited[j])
            {
                visited[j] = true;
                ball++;
            }
        }
    }
}
int main()
{
    FAST for (int i = 0; i < 1000; i++)
    {
        int ones = i % 10;
        int tens = (i / 10) % 10;
        int hundreds = i / 100;
        if (ones!=0&&tens!=0&&hundreds!=0&&ones != tens && tens != hundreds && hundreds != ones)
            isPossible[i] = true;
        else
            isPossible[i] = false;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int a, str, bal;
        cin >> a >> str >> bal;
        for (int i = 0; i < 1000; i++)
        {
            int strike = 0, ball = 0;
            checkStrike(a, i, strike, ball);
            if (!(strike == str && ball == bal))
            {
                isPossible[i] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (isPossible[i]){
            cnt++;}
    }
    cout << cnt << endl;
}
