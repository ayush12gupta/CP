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
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
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
}


Node* reverse_grp(Node* head, int K) {
	if (!head) return NULL;
	Node* curr = head;
	Node* nxt = NULL;
	Node* prev = NULL;
	int cnt = 0;

	while(curr!=NULL && cnt<K) {
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		cnt++;
	}

	if (nxt != NULL) {
		head->next = reverse_grp(nxt, K);
	}

	return prev;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int K; cin>>K;
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5); // HEAD->1->2->3->4->5->NULL
    cout<<"Before reverse grp : ";
    print(&head);
    head = reverse_grp(head, K);
    cout<<"\nAfter reverse grp : ";
    print(&head);
	return 0;
}
