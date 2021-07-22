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
float area(int a, int b, int c){
    float p = (a + b + c)/2.0;
    float ar = pow(p*(p-a)*(p-b)*(p-c),0.5);
    return ar;
}
void sort_by_area(triangle* tr, int n) {
    float dual_area_array[n];
	float *area_array = malloc(n*sizeof(float));
    for(int i=0;i<n;i++){
        area_array[i] = area(tr[i].a, tr[i].b, tr[i].c);
        dual_area_array[i]=area_array[i];
    }
    int j =1;
    
    int *poistion = malloc(n*sizeof(int));
    for(j=1;j<n;j++){
        float key = area_array[j];
        int i = j -1;
        while((i>=0) && area_array[i]>key){
            area_array[i+1] = area_array[i];
            i--;
        }
        area_array[i+1] = key;
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if(area_array[i]==dual_area_array[k]){
                poistion[i]=k;
                break;
            }
        }
    }
    triangle *arr = malloc(n * sizeof(triangle));
    for(int i=0;i<n;i++){
        arr[i].a=tr[poistion[i]].a;
        arr[i].b=tr[poistion[i]].b;
        arr[i].c=tr[poistion[i]].c;
    }
    for(int i=0;i<n;i++){
        tr[i].a=arr[i].a;
        tr[i].b=arr[i].b;
        tr[i].c=arr[i].c;
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
