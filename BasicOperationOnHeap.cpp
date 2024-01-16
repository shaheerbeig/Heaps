#include<iostream>
using namespace std;

class Heap{
    public:
    int size;
    int arr[10];

    Heap(){
        size = 0;
    }

    void insertion(int val){
        arr[0] = -1;
        size = size + 1;
        int N = size;
        //putting the val at the position
        arr[N] = val;
        while(N > 1){
            int parent = N/2;
            if(arr[parent] < arr[N]){
                swap(arr[parent],arr[N]);
                N = parent;
            }
            else{
                return ;
            }
        }
    }
    
    void deletion(){
        //first element ko last wale sa replace kardiya ha
        arr[1] = arr[size];
        //making sure last element is not accessible now
        size--;
        int index = 1;
        while(index < size){
            int root = index;
            int leftindex = 2*index;
            int rightindex = 2*index + 1;

            if(leftindex <= size && arr[root] < arr[leftindex]){
                swap(arr[root] , arr[leftindex]);
                index = leftindex;
            }
            else if(rightindex <= size && arr[root] < arr[rightindex]){
                swap(arr[root] , arr[rightindex]);
                index = rightindex;
            }
            else{
                return ;
            }
        }
    }

    void maxheapify(int arr[] , int  size , int index){
        int largest = index;
        int left = 2*index;
        int right = 2*index + 1;
        if(left <= size && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <= size && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != index){
            swap(arr[largest],arr[index]);
            maxheapify(arr,size,largest);
        }
    }

    void minheapify(int arr[] , int size , int index){
       
        int smallest = index;
        int left = 2*index;
        int right = 2*index + 1;
        if(left <= size && arr[smallest] > arr[left]){
            smallest = left;
        }
        if(right <= size && arr[smallest] > arr[right]){
            smallest = right;
        }
        if(smallest != index){
            swap(arr[smallest],arr[index]);
            minheapify(arr,size,smallest);
        }
    }

    void peek(int arr[] , int size){
        cout<<arr[size]<<endl;
    }

    void print(){
        for(int i=1 ;i<=size ; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Heap h;
    h.insertion(80);
    h.insertion(45);
    h.insertion(35);
    h.insertion(81);
    h.insertion(54);
    h.insertion(30);

    h.print();
    cout<<endl;

    h.deletion();
    h.print();

    int arr2[6] = {-1,45,89,35,80,76};
    int size = 5;

    for(int i=size/2 ; i>0 ; i--){
        h.maxheapify(arr2,size,i);
    } 
    cout<<endl;
    cout<<"After Max Heapify"<<endl;
    for(int i=1;i<=size;i++){
        cout<<arr2[i]<<" ";
    }

    for(int i=size/2 ; i>0 ; i--){
        h.minheapify(arr2,size,i);
    }
    cout<<endl;
    cout<<"After Min Heapify"<<endl;
    for(int i=1;i<=size;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    cout<<"The Element at the top is: ";
    h.peek(arr2,size);
}