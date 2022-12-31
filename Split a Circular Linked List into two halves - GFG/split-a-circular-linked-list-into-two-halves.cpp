//{ Driver Code Starts
/* Program to split a circular linked list into two halves */


#include<stdio.h> 
#include<stdlib.h> 
 
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
 struct Node* newNode(int key)
{
    struct Node *temp = new Node(key);
    
    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

 
/* Driver program to test above functions */
int main()
{
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
	   struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
	   scanf("%d",&n);
	   scanf("%d",&x);
	   head=new Node(x);
	   temp=head;
	   for(i=0;i<n-1;i++){
	   scanf("%d",&x);
	   
	   temp->next=new Node(x);
	   
	   temp=temp->next;
	       
	   }
       
       temp->next=head;
  
       splitList(head, &head1, &head2);
  
     // printf("\nFirst Circular Linked List");
      printList(head1);  
 
     // printf("\nSecond Circular Linked List");
      printList(head2);  
   
   }
  return 0;
}

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if(head->next->next == head){
        *head1_ref = head;
        *head2_ref = head->next;
        (*head1_ref)->next = *head1_ref;
        (*head2_ref)->next = *head2_ref;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prevslow = NULL;
    Node* prevfast = NULL;
    do{
        prevslow = slow;
        prevfast = fast;
        slow = slow->next;
        fast = fast->next->next;
    }while(fast->next != head && fast != head);
    
    if(fast == head){
        prevslow->next = head;
        prevfast =prevfast->next;
        prevfast->next = slow;
        *head1_ref = head;
        *head2_ref = slow;
        
    }
    else{
        
        Node* temp = slow->next;
        slow->next = head;
        fast->next = temp;
        *head1_ref = head;
        *head2_ref = temp;
    }
}