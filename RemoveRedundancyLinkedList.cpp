#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int val;
	node* next;
};

node* getNode(int v, node* nxt)
{
	node* n = new node();
	n->val = v;
	n->next = nxt;
	return n;
}

node* makeLinkedList(vector<int> v)
{
	node* head = getNode(v[0],NULL);
	node* temp = head;

	for(int i=1;i<v.size();i++)
	{
		node* nxt = getNode(v[i],NULL);
		temp->next = nxt;
		temp = temp->next;
	}

	return head;
}

node* removeRedundancy(node* head)
{
	if(head == NULL || head->next == NULL) 
		return NULL;

	map<int,bool> visited;// whether a particular value node is visited or not

	node* temp = head;
	visited[temp->val] = true;

	while(temp->next!=NULL)
	{
		
		if(!visited[(temp->next)->val])
		{
			visited[(temp->next)->val] = true;
			temp = temp->next;
		}
		else//already visited
		{			
			temp->next = (temp->next)->next;//update next pointer of temp to next->next
		}
		
	}

	return head;
}

void printLinkedList(node* head)
{

	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void sampleinput1()
{
	vector<int> v = {3,4,3,5};
	node* head = makeLinkedList(v);
	cout << "Before Removing Redundancy" << endl;
	printLinkedList(head);
	node* head_red = removeRedundancy(head);
	cout << "After Removing Redundancy" << endl;
	printLinkedList(head_red);
}

void sampleinput2()
{
	vector<int> v = {3,4,3,2,6,1,2,6};
	node* head = makeLinkedList(v);
	cout << "Before Removing Redundancy" << endl;
	printLinkedList(head);
	node* head_red = removeRedundancy(head);
	cout << "After Removing Redundancy" << endl;
	printLinkedList(head_red);
}

int main()
{
	sampleinput1();
	cout << "********" << endl;
	sampleinput2();
	return 0;
}