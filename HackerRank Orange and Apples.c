#include<stdio.h>
int BinarySearch(int [], int, int, int);
int main(){
    int s,t,a,b,m,n,i,ansapple=0,ansorange=0;
    scanf("%d%d%d%d%d%d", &s, &t, &a, &b, &m, &n);
    int hsize = t - s + 1;
    int house[hsize];
    for(i=0;i<hsize;i++)
        house[i] = s+i;
    int apple[m], orange[n];
    for(i=0;i<m;i++)
        scanf("%d", &apple[i]);
    for(i=0;i<n;i++)
        scanf("%d", &orange[i]);    
    for(i=0;i<m;i++){
        apple[i] = apple[i] + a;
        ansapple = ansapple + BinarySearch(house, apple[i], 0, hsize-1);
    }
    for(i=0;i<n;i++){
        orange[i] = orange[i] + b;
        ansorange = ansorange + BinarySearch(house, orange[i], 0, hsize-1);
    }
    printf("%d\n%d", ansapple, ansorange);
}
int BinarySearch(int A[], int data, int left, int right){
    int mid;
    mid = (left+right)/2;
    while(left<=right){
        if(data>A[mid])
            return BinarySearch(A, data, mid+1, right);
        else if(data<A[mid])
            return BinarySearch(A, data, left, mid-1);
        else 
            return 1;
    }
    return 0;
}
