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
            cout<<"<->";       
    }
    cout<<endl;
}	

int cntTriplet(Node* head, int x) {
	Node* curr1, *curr2, *curr3;
	int cnt = 0;
	unordered_map<int, Node*> hash;
	for (curr1 = head; curr1!=NULL; curr1 = curr1->next) {
		hash[curr1->data] = curr1;
	}

	for (curr2 = head; curr2!=NULL; curr2 = curr2->next) {
		for (curr3 = curr2->next; curr3!=NULL; curr3 = curr3->next) {
			int p_sum = x - ((curr2->data) + (curr3->data));
			// cout<<p_sum<<endl;
			if (hash.find(p_sum)!=hash.end() && hash[p_sum]!=curr2 && hash[p_sum]!=curr3) {
				cnt++;
			}
		}
	}
	return cnt/3;
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
    int cnt = cntTriplet(head, 6);
    cout<<cnt;
return 0;
}
