#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

#define rep(i,a,b) for(ll i=a;i<b;i++)

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

bool detect_loop(Node* head) {
	Node* curr = head;
    while(curr!=NULL) {
        if (curr->flag ==1) return true;
        curr->flag++;
        curr = curr->next; 
    }
    return false;
}

void remove_loop(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL) {
        if (curr->flag ==1) {
            prev->next=NULL;
            return;
        }
        curr->flag++;
        prev = curr;
        curr = curr->next; 
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int N; cin>>N;
    Node* head = NULL;
    rep(i, 0, N){
    	int tmp;
    	cin>>tmp;
    	push(&head, tmp);
    }
    
    int x; cin>>x;
    // head->next->next->next->next = head;
    if (detect_loop(head)) cout<<"LL contains Loop\n";
    else print(&head);
    
    remove_loop(head);
    print(&head);
return 0;
}
