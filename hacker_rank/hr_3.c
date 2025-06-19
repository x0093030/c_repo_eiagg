#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int i, j;
    float k, l;
    scanf("%d %d %f %f", &i,&j,&k,&l);
    printf("%d %d\n", i+j, i-j);
    printf("%.1f %.1f", k+l, k-l);
    
    return 0;
}