#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 1000;
const int INF = 987654321;
int arr[MAX][MAX];
string result;


int main() {    
    FAST
    int R, C;
    cin >> R >> C;
    if (R % 2) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C - 1; x++)
                if (y % 2 == 0)
                    result += 'R';
                else
                    result += 'L';
            if (y != R - 1)
                result += 'D';
        }
    } else if (!(R % 2) && C % 2)

    {

        for (int x = 0; x < C; x++)

        {

            for (int y = 0; y < R - 1; y++)

                if (x % 2 == 0)

                    result += 'D';

                else

                    result += 'U';

            if (x != C - 1)

                result += 'R';

        }

    } else if (!(R % 2) && !(C % 2))

    {

        pair < int, int > minHappy;

        int minScore = INF;

        for (int y = 0; y < R; y++)

            for (int x = 0; x < C; x++)

        {

            cin >> arr[y][x];

            if ((y + x) % 2 && minScore > arr[y][x])

            {

                minScore = arr[y][x];

                minHappy = {
                    y,
                    x
                };

            }

        }

        int newR = minHappy.first % 2 ? minHappy.first - 1 : minHappy.first;

        for (int y = 0; y < newR; y++)

        {

            for (int x = 0; x < C - 1; x++)

                if (y % 2 == 0)

                    result += 'R';

                else

                    result += 'L';

            result += 'D';

        }

        int newC = minHappy.second;

        for (int x = 0; x < newC; x++)

            if (x % 2 == 0)

                result += "DR";

            else

                result += "UR";

        for (int x = newC; x < C - 1; x++)

            if (x % 2 == 0)

                result += "RD";

            else

                result += "RU";

        if (minHappy.first % 2 == 0)

            newR = R - (minHappy.first + 2);

        else

            newR = R - (minHappy.first + 1);

        for (int y = 0; y < newR; y++)

        {

            result += 'D';

            for (int x = 0; x < C - 1; x++)

                if (y % 2 == 0)

                    result += 'L';

                else

                    result += 'R';

        }

    }

    cout << result << "\n";
}