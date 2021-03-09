#include <stdio.h>
#include <stdlib.h>
#define INVALID -10000000.0
 
float mulInverse(float a, int b)
{
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
    if (a == 1)
    	return (sa>0) ? sa : orig_b+sa;
    else
    	return INVALID;
}
 
int main(){
	int order;
	printf ("\nEnter order of matrix: ");
	scanf ("%d", &order);
	
	int n;
	printf ("\nEnter value of n: ");
	scanf ("%d", &n);
	printf ("\n");
	
	if (order == 3)
	{
		int mat[3][3], i, j;
		float determinant = 0;
		
		printf("Enter elements of matrix row wise:\n");
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
		   scanf("%d", &mat[i][j]);
		
		printf("\nGiven matrix is:");
		for(i = 0; i < 3; i++){
			printf("\n");
			for(j = 0; j < 3; j++)
				printf("%d\t", mat[i][j]);
		}
		
		for(i = 0; i < 3; i++)
			determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
			
		printf ("\n\nDeterminant of the matrix is %f.\n\n", determinant);
		
		determinant = mulInverse (determinant, n);
		
		if (determinant != INVALID) 
		{
			printf ("Multiplicative inverse of the determinant (mod %d) is %f.\n\n", n, determinant);
			
			printf("\n\nInverse of matrix is: \n");
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++)
					printf("%.2f\t",((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant);
				
				printf("\n");
			}
		}
		else 
		{
			printf ("\nMultiplicative inverse does not exist!\n");
			exit(0);
		}
			
	}
	else if (order == 2)
	{
		int mat[2][2], i, j;
		float determinant;
	
		printf("Enter elements of matrix row wise:\n");
		for(i = 0; i < 2; i++)
			for(j = 0; j < 2; j++)
		   scanf("%d", &mat[i][j]);
		   
		printf("\nGiven matrix is:");
		for(i = 0; i < 2; i++){
			printf("\n");
			for(j = 0; j < 2; j++)
				printf("%d\t", mat[i][j]);
		}
		
		determinant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		
		determinant = mulInverse (determinant, n);
		
		if (determinant != INVALID)
		{
			printf("\nInverse of matrix is: \n");
			printf ("%f \t%f\n", mat[1][1] / determinant, -mat[0][1] / determinant);
			printf ("%f \t%f\n", -mat[1][0] / determinant, mat[0][0] / determinant);
		}	
		else
		{
			printf ("Multiplicative inverse does not exist!\n");
			exit(0);
		}
		
		
	}
   	return 0;
}
