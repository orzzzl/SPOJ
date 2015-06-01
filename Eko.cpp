/*************************************************************************
	> File Name: a.cpp
	> Author: Zeleng Zhuang
	> Mail: zhuangzeleng19920731@gmail.com
	> Created Time: Mon Apr 20 20:15:23 2015
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
const int INF = (int)1E9;
#define MAXN 600005
#define vv vector<int>
#define FILL(x,v) memset(x,v,sizeof(x))


int main () {
    ll n, m;
    cin >> n >> m;
    unsigned x [1000005];
    unsigned hh [1000000];

    REP (i, 0, n) {
        scanf ("%d", x + i);
    }

    
    sort (x, x + n);

    ll res = 0;
    hh [n] = 0;
    for (int i = n - 1; i > 0; i --) {
        ll tmp = n - i;
        hh [i] = x [i] - x [i - 1];
        res += tmp * hh [i];
        if (res > 2 * 1E9)
            res = 2 * 1E9 + 1;
        hh [i] = res;
    }

    res += n * x [0];
    hh [0] = res;

    int left = 0, right = n;
    while (left <= right) {
        int mid = (1 + left + right) / 2;
        if (hh [mid - 1] < m) right = mid - 1;
        if (hh [mid] > m) left = mid + 1;
        if (hh [mid - 1] >= m && hh [mid] <= m) {
            unsigned fuck = n + 1 - mid;
            cout << (x [mid - 1] - (fuck - 1 + m - hh [mid]) / fuck) << endl;
            return 0;
        }

    }

    return (0);
}
