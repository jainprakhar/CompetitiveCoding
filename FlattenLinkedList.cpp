#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}


Node* merge(Node* a, Node* b)
{
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    Node* result;
    if(a->data > b->data)
    {
        result = b;
        b = b->bottom;
    }
    else
    {
        result = a;
        a = a->bottom;
    }
    Node* temp = result;
        
    while(a != NULL && b!= NULL)
    {
        if(a->data > b->data)
        {
            result->bottom = b;
            b = b->bottom;
        }
        else
        {
            result->bottom = a;
            a = a->bottom;
        }
        
        result = result->bottom;
    }
    
    while(a!=NULL)
    {
        result->bottom = a;
        a = a->bottom;
        result = result->bottom;
    }
    
    while(b!=NULL)
    {
        result->bottom = b;
        b = b->bottom;
        result = result->bottom;
    }
    
    return temp;
}
    
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL)
    return root;
    
    return (merge(root,flatten(root->next)));
}