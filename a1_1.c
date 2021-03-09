#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int mulInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

int addInverse(int a, int m)
{
  int i, x;
  for (i = -MAX; i < MAX; i++)
  {
  	x = -a + i*m;
  	if (x >= 0 && x <= m-1)
  		return x;
  }
}

int main()
{
    int a, n;
    printf ("\nValue of n: ");
    scanf ("%d", &n);
    printf ("\nValue of a: ");
    scanf ("%d", &a);
    printf ("\nMultiplicative inverse of %d (mod %d) is: %d\n", a, n, mulInverse(a, n));
    printf ("\nAdditive inverse of %d (mod %d) is: %d\n\n", a, n, addInverse(a, n));
    return 0;
}

