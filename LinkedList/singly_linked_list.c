#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

Node* createNode(int val)
{
	Node* temp = (Node*)(malloc(sizeof(Node)));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void print_list(Node* root)
{
	Node* head = root;
	printf("List : ");
	while(head->next != NULL)
	{
		head = head->next;
		printf("%d ", head->data);	
	}
	printf("\n");
}

int size(Node* root)
{
	Node* head = root;
	int count = 0;
	while(head->next != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void push_front(Node* root ,int val)
{
	Node* head = root;
	Node* temp = createNode(val);
	temp->next = head->next;
	head->next = temp;
}

int pop_front(Node* root)
{
	Node* head = root;
	Node* temp = head->next;
	int val = temp->data;
	head->next = temp->next;
	free(temp);
	return val;
}

void push_back(Node* root, int val)
{
	Node* head = root;
	while(head->next != NULL)
	{
		head = head->next;
	}
	Node* temp = createNode(val);
	head->next = temp;
	temp->next = NULL;
}

int pop_back(Node* root)
{
	Node* head = root;
	while(head->next->next != NULL)
	{
		head = head->next;
	}
	int val = head->next->data;
	head->next = NULL;
	return val;
}

int front(Node* root)
{
	Node* head = root;
	return head->next->data;
}

int back(Node* root)
{
	Node* head = root;
	while(head->next->next != NULL)
	{
		head = head->next;
	}
	int val = head->next->data;
	return val;
}

int valueAt(Node* root, int index)
{
	Node* head = root;
	int count = 0;
	while(count<index && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	return head->data;
}

void insertAt(Node* root, int index, int val)
{
	Node* head = root;
	int count = 0;
	while(count<index-1 && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	Node* temp = createNode(val);
	temp->next = head->next;
	head->next = temp;
}

void erase(Node* root, int index)
{
	Node* head = root;
	int count = 0;
	while(count<index-1 && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	Node* temp =  head->next;
	head->next = temp->next;
	free(temp);
}

Node* reverse(Node* root)
{	
	if(size(root)>1)
	{
		Node* head = root;
		Node* next = head->next;
		Node* future = head->next->next;
		int count = 0 ;
		while(future != NULL)
		{
			next -> next = head;
			if(count == 0) next -> next = NULL;
			head = next;	
			next = future;
			future = future->next;	
			count++;
		}
		free(future);
		next -> next = head;
		root -> next = next;		
	}	
	return root;
}

int value_from_end(Node* root, int index)
{
	Node* head = root;
	Node* rev = reverse(head);
	int val = valueAt(rev, index);
	root = reverse(rev);
	return val;g
}

void remove_val(Node* root, int val)
{
	Node* head = root;
	int count = 0;
	while(head->next != NULL && head->data != val)
	{
		head = head->next;
		count++;
	}
	if(head->next != NULL)
	{
		erase(root, count);
	}
}

int main()
{
	printf(" 1. push_front  2.size     3.print    4.pop_front  5.push_back   6.pop_back 7.front 8.back \n");
	printf(" 9. valueAt    10.eraseAt 11.reverse 12.insertAt  13.remove_val 14.valueAt_n_from end 15.exit\n");
	int choice = 0, data, index;
	scanf("%d",&choice);
	Node* head;
	head->next=NULL;
	while(choice != 15)
	{		
		switch(choice)
		{
			case 1: scanf("%d",&data);
					push_front(head, data);
					print_list(head);
					break;
			case 2:	printf("%d\n", size(head));
					break;
			case 3:	print_list(head);
					break;
			case 4:	printf("%d\n", pop_front(head));
					print_list(head);
					break;
			case 5: scanf("%d",&data);
					push_back(head, data);
					print_list(head);
					break;
			case 6:	printf("%d\n", pop_back(head));
					print_list(head);
					break;
			case 7:	printf("%d\n", front(head));
					print_list(head);
					break;
			case 8:	printf("%d\n", back(head));
					print_list(head);
					break;
			case 9:	scanf("%d",&index);
					printf("%d\n", valueAt(head, index));
					print_list(head);
					break;	
		   case 10: scanf("%d",&index);
					erase(head, index);
					print_list(head);
		   			break;	
		   case 11:	print_list(reverse(head));
		   			break;
		   case 12: scanf("%d",&index);
		   			scanf("%d",&data);
					insertAt(head, index, data);
					print_list(head);
		   			break;
		   case 13: scanf("%d",&data);
					remove_val(head, data);
					print_list(head);
		   			break;
		   case 14: scanf("%d",&data);
					printf("%d\n",value_from_end(head, data));
		   			break;		
			default:printf("Exitting\n");
		}
		fflush(stdout);
		scanf("%d",&choice);
	}
	return 0;
}