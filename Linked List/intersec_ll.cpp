#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

struct Node {
    int data;
    int flag;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
        this->flag = 0;
    }
};

void push(Node** headref, int data) {
    Node* new_node = new Node(data);
    new_node->next = (*headref);
    (*headref) = new_node;
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

Node* intersection_head(Node* first, Node* second) {
	if (first==NULL || second==NULL) return NULL;

	if (first->data > second->data) {
		return intersection_head(first, second->next);
	}

	if (first->data < second->data) {
		return intersection_head(first->next, second);
	}

	Node* tmp = new Node(first->data);
	// tmp->data = ;

	tmp->next = intersection_head(first->next, second->next); 
	return tmp;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Node* head1 = NULL;
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);

    Node* head2 = NULL;
    push(&head2, 6);
    push(&head2, 3);
    push(&head2, 1);

    Node* inters_head = intersection_head(head1, head2);
    print(&inters_head);
	return 0;
}
