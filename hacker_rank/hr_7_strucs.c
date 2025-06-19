#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(triangle tr)
{ 
    double p = (tr.a+tr.b+tr.c)/2.0;
    double s = sqrt(p*(p-tr.a)*(p-tr.b)*(p-tr.c));
    //printf("%.2f ", p);
    return (s);
}

void sort_by_area(triangle* tr, int n)
{
	/**
	* Sort an array a of the length n
	*/
    triangle tmp;
    for (int i = 0; i < n; i++) {
        //area(tr[n]);
        for (int j=i+1; j<n; j++)
            if (area(tr[i])>area(tr[j])){
                tmp = tr[i];
                tr[i]=tr[j];
                tr[j]=tmp;
            }
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}