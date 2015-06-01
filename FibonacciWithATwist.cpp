/*************************************************************************
	> File Name: cc.cpp
	> Author: Zeleng Zhuang
	> Mail: zhuangzeleng19920731@gmail.com
	> Created Time: Thu Apr 16 01:16:45 2015
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

ll nn, mm;

void mult (ll a [2][2], ll b [2][2]) {
    for (int i = 0; i <= 1; i ++)
        for (int j = 0; j <= 1; j ++)
            {
                a [i][j] = a [i][j] % mm;
                b [i][j] = b [i][j] % mm;
            }
    ll aa = a [0][0] % mm * b [0][0] % mm + a [0][1] % mm * b [1][0] % mm;
    ll ab = a [0][0] % mm * b [0][1] % mm + a [0][1] % mm* b [1][1] % mm;
    ll ba = a [1][0] % mm * b [0][0] % mm + a [1][1] % mm* b [1][0] % mm;
    ll bb = a [1][0] % mm * b [0][1] % mm + a [1][1] % mm* b [1][1] % mm;

    a [0][0] = aa % mm;
    a [0][1] = ab % mm;
    a [1][0] = ba % mm;
    a [1][1] = bb % mm;
}

void poh (ll a [2][2], ll n) {
    ll m [2][2] = {{1, 1}, {1, 0}};
    if (n == 0 || n == 1)    return;
    poh (a, n / 2);
    mult (a, a);

    if (n % 2) mult (a, m);
}


ll fib (ll n) {
    ll f [2][2] = {{1, 1}, {1, 0}};
    poh (f, n - 1);
    return f [0][0];
}

int main () {
    int tests;
    cin >> tests;
    while (tests --) {
        cin >> nn >> mm;
        ll myans= (mm + 2 * (fib (nn + 2) % mm)- (nn + 2) % mm) % mm;
        cout << myans << endl;
    }
    return (0);
}
