/*Selection sort*/
#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,5,2,1,40};
    cout << "The unsorted array is: ";
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";
    for(int i=0;i<5;i++){
        int small = i;
        for(int j=i+1;j<=5;j++){
            if(arr[small]>arr[j])
                small = j;
        }
        int temp = arr[small];
        arr[small]=arr[i];
        arr[i]=temp;
        
    }
    cout << "\nThe sorted array is: ";
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";
}
