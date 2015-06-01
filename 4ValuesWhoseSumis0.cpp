/*************************************************************************
	> File Name: b.cpp
	> Author: Zeleng Zhuang
	> Mail: zhuangzeleng19920731@gmail.com
	> Created Time: Fri Apr 24 01:40:00 2015
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
    int tests, res = 0;
    cin >> tests;
    vv lista, listb, listc, listd, qlg, hlg;
    for (int cn = 1; cn <= tests; cn ++) {
        int a, b, c, d;
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        lista.push_back (a);
        listb.push_back (b);
        listc.push_back (c);
        listd.push_back (d);
    }

    REP (i, 0, tests) REP (j, 0, tests) {
    	qlg.push_back (lista[i] + listb[j]);  
        hlg.push_back (listc[i] + listd[j]);
    }
    sort (hlg.begin (), hlg.end ());

    for (int i = 0; i < tests * tests; i ++) {
        int tmp = lower_bound (hlg.begin(), hlg.end(), -qlg [i]) - hlg.begin ();
        int j = tmp;
        for (; j < tests * tests && hlg [j] == -qlg [i]; j++) 
            res ++;
    }
    cout << res << endl;
    return (0);
}