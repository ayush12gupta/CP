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
    cout<<endl;
}

// Hashing Approach
void removeDuplicated(Node* head) {
	unordered_set<int> s;
	Node* curr = head;
	Node* prev = NULL;
	while(curr!=NULL) {
		int tmp = curr->data;
		if (s.find(tmp)!=s.end()) {
			prev->next = curr->next;
			curr = curr->next;
			continue;
		}
		s.insert(tmp);
		prev = curr;
		curr = curr->next;
	}

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 6);
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    print(&head);
    removeDuplicated(head);
    print(&head);
	return 0;
}
