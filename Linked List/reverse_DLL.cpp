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

Node* reverse(Node* head) {
	if (head==NULL || head->next==NULL) return head;
	Node* curr = head;
	Node* tmp;
	// if (head==NULL )
	while(curr!=NULL) {
		tmp = curr->next;
		curr->next = curr->prev;
		curr->prev = tmp;
		if(curr->prev==NULL) break;
		curr = curr->prev;
	}
	return curr;
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    // print(&head);
    Node* rev = reverse(head);
    print(&rev);
    // cout<<rev->p->data;
return 0;
}
