#include <bits/stdc++.h>
using namespace std;
#define MAXNUM 40000

bitset <MAXNUM> bs;
vector <int> pr;
bool isP (long long a) {
    if (a < MAXNUM)
        return bs [a];
    else {
	for (int i = 0; i < pr.size (); i ++)
            if (a % pr[i] == 0)    return 0;
	return 1;
    }} 

int main () {
    int T;
    scanf ("%d\n", &T);
    bs.set ();
    bs [0] = 0;
    bs [1] = 0;

    for (long long i = 2; i < MAXNUM; i ++) {
        if (bs [i]) {
	    for (long long j = i * i; j < MAXNUM; j += i)
	        bs [j] = 0;
	    pr.push_back ((int)i);
	}
    }

    while (T --) {
	long long a, b;
	scanf ("%lld %lld", &a, &b);
        long long p;
	for (p = a; p <= b; p ++)
	    if (isP (p)) 
		printf ("%lld\n", p);
	puts ("");
    }
    return 0;
}
