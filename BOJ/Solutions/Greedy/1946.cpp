#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int T, N;
int cnt_array[21];
pair<int,int> score[100000];
int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> score[j].first >> score[j].second;
		}

		sort(score, score + N); 


		int max_score = score[0].second;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (score[i].second <= max_score) {
				cnt++;
				max_score = score[i].second;
			}
		}

		cnt_array[i] = cnt;
		
	}

	for (int i = 0; i < T; i++) {
		cout << cnt_array[i]<<endl;
	}


	return 0;
} 