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

void findPairs(Node* head, int x) {
	// if head==NULL
	Node* last = head;
	while(last->next != NULL && last->data<=x) {
		last = last->next;
	}

	bool res = true;

	while(head!=last && head->next!=last) {
		int sum = (head->data + last->data);
		if (sum == x) {
			cout<<'('<<head->data<<", "<<last->data<<")"<<endl;
			head = head->next;
			last = last->prev; 
		}
		else{
			if (sum < x) {
				head = head->next;
			}
			else {
				last = last->prev;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print(&head);
    findPairs(head, 7);
return 0;
}
