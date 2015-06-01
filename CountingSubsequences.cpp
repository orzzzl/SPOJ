#include <bits/stdc++.h>
using namespace std;

int T;

int main () {
    cin >> T;
    while (T --) {
	long long n;
	cin >> n;
	long long dp [n + 5];
	long long i = 1;
	dp [0] = 0;
	for (;i <= n; i ++) {
	    scanf ("%lld", dp + i);
	    dp [i] += dp [i - 1];
	}
	int res = 0;
	long long j = 0;
	map <long long, int> mm;
	for (int j = 0; j <= n; j ++) {
	    res += mm[(dp [j] - 47)];
	    mm [dp[j]] ++;
	}
	cout << res << endl;
    }
    return 0;
}
