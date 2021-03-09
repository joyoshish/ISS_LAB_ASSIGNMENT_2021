#include <stdio.h>
#include <stdlib.h>

int euclideanGCD(int a, int b)
{
  int q, r;
  while (a != 0)
  {
    q = b/a;
    r = b - q*a;
    b = a;
    a = r;
  }
  return b;
}

int main()
{
  int a,b;
  printf ("Enter 2 numbers(Greater, Smaller): ");
  scanf ("%d %d", &b, &a);
  printf ("\nGCD of %d and %d is: %d\n", a, b, euclideanGCD(a, b));
  return 0;
}

