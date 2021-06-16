#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back


struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

void push(Node** headRef, int data) {
	Node* new_node = new Node(data);
	new_node->prev = NULL;
	new_node->next = (*headRef);

	if ((*headRef)!= NULL) (*headRef)->prev = new_node;
	(*headRef) = new_node;
}

void print(Node **headref) {
    Node* curr = (*headref);
    while(curr != NULL) {
        cout<<curr->data;
        curr = curr->next;
        if (curr!=NULL)
            cout<<"-->";       
    }
    cout<<endl;
}

void rotateList(Node** headRef, int K) {
	Node* head = (*headRef);
	Node* parti = head;
	Node* last = head;
	while(last->next!=NULL) {
		if (K>0){
			K--;
			parti = parti->next;
		}
		last = last->next;
	}

	last->next = head;
	head->prev = last;
	Node* nlast = parti->prev;
	parti->prev = NULL;
	nlast->next = NULL;
	(*headRef) = parti;
} 

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
	print(&head);
	rotateList(&head, 7);
	print(&head);

	return 0;
}
