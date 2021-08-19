//The value of k is 10 and value of n is 5
#include<stdio.h>
int main(){
    int A[5] = {6,3,2,9,7};
    printf("Array before sort is: ");
    for(int i=0;i<5;i++)
        printf("%d ", A[i]);
    int B[5], C[10];
    for(int i=0;i<10;i++)
        C[i]=0;
    for(int j=0;j<5;j++)
        C[A[j]] = C[A[j]] + 1;
    for(int p=1;p<10;p++)
        C[p] = C[p]+C[p-1];
    for(int j=4;j>=0;j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    printf("\nArray after sort is: ");
    for(int i=0;i<5;i++)
        printf("%d ", B[i]);
}
