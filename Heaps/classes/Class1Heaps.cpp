# include <iostream>
using namespace std;

class Heap{
    public:
        int *arr;
        int capacity;
        int size;

        Heap(int capacity){
            this->arr = new int [capacity];
            this->capacity=capacity;
            //Size will tell us the current size of the array
            this->size=0;
        }

        void insert(int val){
            if(size==capacity){
                cout<<"Heap Overflow"<<endl;
                return;
            }else{
                size++;
                int index=size;
                arr[index]=val;
                // Take the value to its current position
                while(index>1){
                    int parInd=index/2;
                    if(arr[index]>arr[parInd]){
                        swap(arr[index], arr[parInd]);
                        parInd=index;
                    } else{
                        break;
                    }
                }
            }
        }

        int deleteFromHeap() {
            int answer = arr[1];
            //replacement
            arr[1] = arr[size];
            //last element ko delete uski original position se
            size--;
            int index = 1;
            while(index < size ) {
                int leftIndex = 2*index;
                int rightIndex = 2*index+1;

                //find out karna h , sabse bada kon
                int largestKaIndex = index;
                //check left child
                if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]) {
                    largestKaIndex = leftIndex;
                }
                if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]) {
                    largestKaIndex = rightIndex;
                }
                //no change
                if(index == largestKaIndex) {
                    break;
                }
                else {
                    swap(arr[index], arr[largestKaIndex]);
                    index = largestKaIndex;
                }
            }
            return answer;
        }

        void printHeap(){
            cout<<"Printing the value of Heap"<<endl;
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }  
};

void heapify(int *arr, int size, int index){
    int leftIndex=2*index;
    int rightIndex=2*index+1;
    int largestIndex=index;
    if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
        largestIndex = leftIndex;
    }
    if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
        largestIndex = rightIndex;
    }
    if(index!=largestIndex){
        swap(arr[index], arr[largestIndex]);
        //Ab Recursion Sambhalega
        index=largestIndex;
        heapify(arr, size, index);
    }
    //Here there is no need of base case as when the code has index==largestIndex then the code will automatically stop
    //So there is no need of any base case
}

void arrayToHeap(int arr[], int size){
    for(int i=size/2; i>0; i--){
        heapify(arr, size, i);
    }
    //Since all the nodes form n/2 to n are leaf nodes so we do not need to use heapify in this case
    //The time complexity is O(n) and not O(nlogn)
}

void HeapSort(int arr[], int n){
    while(n!=1){
        swap(arr[1], arr[n]);
        //Here it is 1 based indexing so we will have index starting from n so we will have to use n and not n-1
        n--;
        heapify(arr,n,1);
    }
}

int main(){

    int arr[] = {-1,5,10,15,20,25,12};
    //We are putting index as -1 in the start because we are starting index from 1
    int n = 6;
    arrayToHeap(arr,6);
    
    cout << "printing heap: " << endl;
    for(int i=1; i<=6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    HeapSort(arr, n);
    cout << "printing heap: " << endl;
    for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

    Heap h(20);
    //inserting
    h.insert(20);
    h.insert(10);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.printHeap();
    int answer=h.deleteFromHeap();
    cout<<"answer"<<endl;
    h.printHeap();
    return 0;
}