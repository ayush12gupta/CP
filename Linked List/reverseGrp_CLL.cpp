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

void push(Node** headRef, Node* new_node) {
	// Node* new_node = new Node(data);
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
            cout<<" <-> ";       
    }
    cout<<endl;
}

Node* reverseGrp(Node* head, int k) {
	if (!head) return head;
	Node* curr = head, *next = NULL;
	Node* newHead = NULL;
	int cnt=0;
	while( curr!= NULL && cnt<k) {
		next = curr->next;
		push(&newHead, curr);
		curr = next;
		cnt++;
	}

	if (next != NULL) {
		head->next = reverseGrp(next, k);
		head->next->prev = head;
	}

	return newHead;
}

Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
    print(&head);
    Node* headn = reverseGrp(head, 2);
    print(&headn);
	return 0;
}
