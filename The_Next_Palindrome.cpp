#include <bits/stdc++.h>
using namespace std;


int main () {
    int n;
    scanf ("%d", &n);
    while (n --) {
	string tmp;
	cin >> tmp;
	int x = tmp.size () - 1;
	while (tmp [x] == '9') {
	    tmp [x] = '0';
	    x --;
	    if (x < 0) {
		tmp = "0" + tmp;
		x = 0;
		break;
	    }
	}

	tmp [x] ++;
	int ii = tmp.size () % 2;
	int s = tmp.size () - 1;
	int m = tmp.size () / 2 - 1;
	x = s;
	int ok = 0;
	int y = m;
	if (tmp [m] > tmp [s - m]) {
	    tmp [s - m] = tmp [m];
	    ok = 1;
	}
	if (tmp [m] <= tmp [s - m] && !ok)
	{
	    x = m + ii;
	    
	    while (tmp [m] == tmp [s - m]) {
		ok = 2;
		m --;
		if (m < 0)
		{
		    ok = 4;
		    break;
		}
	    }
	    if (ok != 4 && tmp [s - m] < tmp [m]) ok = 5;
	    while (tmp [x] == '9' && ok != 4 && ok != 5) {
		tmp [x] = '0';
		x --;
		if (x < 0) {
		    tmp = "0" + tmp;
		    x = 0;
		    s ++;
		    break;
		}
	    }
	    if ( ok != 4 && ok != 5)
		tmp [x] ++;
	}   
	for (int j = s - y ; j <= s; j ++)
	    tmp [j] = tmp [s - j];
       
	cout << tmp << endl;
    }
    return 0;
}
