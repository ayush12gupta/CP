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

bool checkCircular(Node* head) {
	int flag = 0;
	Node* curr = head->next;
	while(curr != head){
		if (curr==NULL) return false;
		curr = curr->next;
	}
	return true;
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
    // Creating the link b/w the last node and first node
    // head->next->next->next->next = head;
    if (checkCircular(head)) cout<<"Circular Linked List\n";
    else cout<<"Not a Circular Linked List\n";

	return 0;
}
