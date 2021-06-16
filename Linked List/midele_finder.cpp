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

Node* midFinder(Node* head) {
	Node *fast, *slow;
	fast = head;
	slow = head;
	while(fast!=NULL) {
		fast = fast->next;
		if(fast!=NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	// slow = slow->next;
	return slow;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    // push(&head, 6);    
    push(&head, 7);
    push(&head, 8);
    push(&head, 3);
    push(&head, 4);
    print(&head);
    Node* mid = midFinder(head);
    cout<<mid->data;
 	
 	return 0;
}
