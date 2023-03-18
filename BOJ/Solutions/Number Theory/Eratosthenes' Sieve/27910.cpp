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


/* 
author: hyeok2044
Written at 2023-03-18 19:47
Problem: 27910
Problem Name: Logaritam
Link: https://www.acmicpc.net/problem/27910
Memo: find the largest prime and print n/that prime-1
when m=1, impossible because there is no prime
*/

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
const int MAX = 501;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

//find a largest prime number and print n/lp-1

int main()
{
    FAST
	int n, m;
	cin >> n >> m;
	bool isPrime[20001];
	for (int i = 2; i < 20001; i++)
	{
		isPrime[i] = true;
	}
	for (int i = 2; i < 20001; i++)
	{
		if(isPrime[i]){
			for (int j = i*i; j < 20001; j+=i)
			{
				isPrime[j] = false;
			}
			
		}
	}
	vector<int> primes;
	for (int i = 0; i < 20001; i++)
	{
		if(isPrime[i])primes.push_back(i);
	}
	
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if(k==1){
			cout<<-1<<endl;
		}
		else{
			int pos = upper_bound(all(primes), k)-primes.begin();
			int val = 1;
			for (int i = pos-1; i >=0; i--)
			{
				while(k%primes[i]==0){
					val = max(val, primes[i]);
					k/=primes[i];
				}
			}
			val = max(k, val);
			cout<<n/val-1<<endl;
			

		}
	}
	
	
}
	


    


