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

bool compareBoth(Node** first, Node** second) {
	if ((*first)->next==NULL) return ((*first)->data == (*second)->data);
	while((*first)!=NULL && (*second)!=NULL) {
		if((*first)->data != (*second)->data) return false;
		(*first) = (*first)->next;
		(*second) = (*second)->next;
	}
	return true;
}

// As we have to so in O(1) space complexity
void reverse(Node** headRef) {
	Node* curr = (*headRef);
	Node* prev = NULL;
	Node* next;
	while(curr!=NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*headRef) = prev;
}

/*
1) Find the mid point of LL
2) Reverse the second half
3) Compare both halves
*/
bool checkPalindrom(Node* head) {
	// cout<<head;
	// Partitioning into 2 halves
	Node* slow = head;
	Node* fast = head;
	Node* first = head;
	Node* prev=head;
	Node* second;
	bool res = true;
	if (head->next->next == NULL){
		cout<<"CASE1\n";
		if (head->data == head->next->data) res = true;
		else res = false;
	}

	else if (head != NULL && head->next!=NULL){
		
		while(fast->next!=NULL && fast->next->next!=NULL) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		// No. of nodes is even
		if (fast->next != NULL && fast->next->next == NULL) {
			fast = fast->next;
			second = slow->next;
			fast->next = NULL;
			slow->next = NULL;
			reverse(&second);
			// print(&second);
			res = compareBoth(&first, &second);
		}
		// No. of nodes was odd
		else {
			second = slow->next;
			fast->next = NULL;
			prev->next = NULL;
			print(&first);
			reverse(&second);
			res = compareBoth(&first, &second);
		}
	}
	// else if(head->)
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 3);
    push(&head, 3);
    // push(&head, 1);
    print(&head);
    // reverse(&head);
    if (checkPalindrom(head)) cout<<"Pallindrom\n";
    else  cout<<"Not a Pallindrom\n";
    // print(&head);
	return 0;
}
