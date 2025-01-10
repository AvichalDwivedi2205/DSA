# include <iostream>
# include <queue>
using namespace std;

class Info{
    public:
      int data;
      int rowIndex;
      int colIndex;

      Info(int data, int rowI, int colI){
        this->data = data;
        this->rowIndex = rowI;
        this->colIndex = colI;
      }
};

class Compare{
    public:
       bool operator()(Info* a, Info* b){
        return a->data > b->data;
        //Condition For Min Heap
        //If we make it a->data<b->data then we would have created max heap. 
       }  
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans){
    priority_queue<Info*, vector<Info*>, Compare> pq;
    //Since we are creting objects of info directly so we will need to store the pointers in the priority queue
    // Process first k elements
    for(int row=0; row<k; row++){
        Info* element = new Info(arr[row][0], row, 0);
        pq.push(element);
    }

    while(!pq.empty()){
        Info* temp=pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow =  temp->rowIndex;
        int topCol = temp->colIndex;

        //store in answer
        ans.push_back(topData);

        //Now we need to indert the next element inside of the priority queue for further calculations
        //This element will be teh next element of the array then just got popped i.e. the next element of the temp
        if(topCol+1<n){
            //Now insert this element as it is not going out of bound
            Info* next = new Info(arr[topRow][topCol+1], topRow, topCol+1);
            pq.push(next);
        }
    }
}

int main(){
    int arr[3][4] = {
        {1,4,8,11},
        {2,3,6,18},
        {5,7,12,14}
    };
    int n=4;
    int k=3;

    vector <int> ans;
    mergeKSortedArrays(arr, n, k, ans);
     cout<<"Printing arrays"<<endl;
     for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
     }
     cout<<endl;
}