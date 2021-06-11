/*Binary Search Recursion*/
#include<stdio.h>
int BinarySearch(int [], int, int, int);
int main()
{
    int n,data;
    int place;
    printf("Enter the Number: ");
    scanf("%d", &data);
    int A[13] = {1,4,6,8,10,25,67,78,98,100,201,403,607};
    place = BinarySearch(A, data, 0, 12);
    printf("The index is: %d and position is: %d", place, place+1);
}
int BinarySearch(int A[], int data, int left, int right)
{
    int mid;
    mid = (left + right) / 2;
    while(left<=right)
    {
        if(data==A[mid])
            return mid;
        else if(data>A[mid])
            return BinarySearch(A, data, mid+1,right);
        else
            return BinarySearch(A, data, left, mid-1);
    }
    return -1;
}

