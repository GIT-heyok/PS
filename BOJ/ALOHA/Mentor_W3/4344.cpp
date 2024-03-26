#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    FAST
    int TC; // 테스트 케이스이다.
    cin >> TC;
    while(TC--){ // C++에서는 0은 거짓을 뜻한다. 이렇게 하면 TC번 반복하는 반복문이 된다.
        int n;
        cin >> n;
        double arr[n]; // 나눗셈을 수행해야하니 double로 받아준다.
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        double sum = 0; // 총합을 저장하는 변수이다.
        for (int i = 0; i < n; ++i) {
            sum += arr[i]; // 계속 더해주자.
        }
        double average = sum/n; // 평균은 총 합/학생수 이다.
        int count = 0; // 평균을 넘는 학생 수를 저장하는 변수이다.
        for (int i = 0; i < n; ++i) {
            if(arr[i] > average){
                count++; // 평균을 넘는 학생이면 더해준다.
            }
        }
        // <bits/stdc++.h> 헤더에 있는 fixed, setprecision을 이용하면 반올림을 쉽게 할 수 있다.
        cout << fixed << setprecision(3) << count*100.0/n << "%" << endl;
    }
}
