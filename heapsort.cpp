#include<iostream>
using namespace std;

void heapify(int arr[] , int size , int index){
    int largest = index;
    int leftindex = 2*index ;
    int rightindex = 2*index + 1; 

    if(leftindex <= size && arr[largest] < arr[leftindex]){
        largest = leftindex;
    }
    if(rightindex <= size && arr[largest] < arr[rightindex]){
        largest = rightindex;
    }
    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
    else{
        return ;
    }
}

void sort(int arr[] , int n){
    //step 1
    int size = n;

    while(size > 1){
        swap(arr[size] , arr[1]);
        size--;

        //since 1 is the root 
        heapify(arr,size,1); 
    }
}

int main(){
    int size = 5 ; 
    int arr[6] = {-1,52,89,35,76,45};
    for(int i=size/2 ; i>0 ; i--){
        heapify(arr,size,i);
    }

    sort(arr,size); 
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}