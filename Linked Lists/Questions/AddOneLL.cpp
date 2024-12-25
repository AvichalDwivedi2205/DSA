# include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
  
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        Node* temp = head;
        int carry=1;
        while(temp->next!=NULL){
            int sum=(temp->data)+carry;
            int digit=sum%10;
            carry=sum/10;
            temp->data=digit;
            temp=temp->next;
            if(carry==0){
                break;
            }
        }
        
        if(carry!=0){
            int sum=(temp->data)+carry;
            int digit=sum%10;
            carry=sum/10;
            temp->data=digit;
            if(carry!=0){
                Node* newNode = new Node(carry);
                temp->next=newNode;
            }
        }
        return reverse(head);
    }
};