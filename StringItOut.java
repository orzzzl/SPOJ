import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class Main {
	static int res = 0;
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner (System.in);
        int tests = in.nextInt();
        for (int cn = 1; cn <= tests; cn ++) {
        	String x, y;
        	x = in.next();
        	y = in.next();
        	int mid = -1, l = 0, r = 500022;
        	while (l <= r) {
        		mid = (l + r) / 2;
        		if (cando (x, y, mid) && !cando (x, y, mid + 1)) {
        			break;
        		}
        		else {
        			if (cando (x, y, mid))
        				l = mid;
        			else
        				r = mid;
        		}
        	}
        System.out.println (mid);
        }
	}
	
	public static boolean cando (String a, String b, int n) {
		int num = n;
		int i = 0, j = 0;
		for (; i < a.length(); i ++) {
			num = n;
			for (; j < b.length () && num != 0; j ++) {
				if (b.charAt(j) == a.charAt(i))
					num --;
			}
			if (num != 0)
				return false;
		}
		return true;
	}
	
}
