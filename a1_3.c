#include <stdio.h>
#include <stdlib.h>

int main() {
    long long a, b;
    scanf ("%lld %lld", &a, &b);
    
    long long orig_a = a, orig_b = b;
    long long q, r, sa = 1, sb = 0, ta = 0, tb = 1, sc, tc;
    
    do {
        q = a/b;
        r = a-q*b;
        a = b;
        b = r;
        sc = sa-q*sb;
        sa = sb;
        sb = sc;
        tc = ta-q*tb;
        ta = tb;
        tb = tc;
    } while (b != 0);
    
    printf ("\nGCD is %lld = %lldx%lld + %lldx%lld.\n", a, sa, orig_a, ta, orig_b);
    if (a == 1) {
    	printf ("Multiplicative inverse (%lld^(-1))mod(%lld) = %lld.\n", orig_a, orig_b, (sa>0) ? sa : orig_b+sa);
    }
    else {
    	printf ("Multiplicative inverse does not exist.\n");
    }
}

