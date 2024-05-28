/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */
void freeNode(Node* ptr);

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------[�ֳ���]-----[2023041039]-----------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

/* Ʈ�� �ʱ�ȭ ��尡 ����Ű�� ���������Ͱ� ��Ʈ���*/
int initializeBST(Node** h) { 

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) 
		freeBST(*h); 

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); 
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}


/*���� ��ȸ*/
void inorderTraversal(Node* ptr) 
{
	if(ptr != NULL) // ptr�� ������� ������
	{
		inorderTraversal(ptr->left); // �������� �̵�
		printf(" [%d] ",ptr->key); // key�� ���
		inorderTraversal(ptr->right); // ���������� �̵�
	}
}

/*���� ��ȸ*/
void preorderTraversal(Node* ptr)
{
	if(ptr != NULL) // ptr�� ������� �ʴٸ�
	{
		printf("[%d] ",ptr->key); // key�� ���
		preorderTraversal(ptr->left); // �������� �̵�
		preorderTraversal(ptr->right); // ���������� �̵�
	}
}

/*���� ��ȸ*/
void postorderTraversal(Node* ptr)
{
	if(ptr != NULL) // ptr�� ������� �ʴٸ�
	{
		postorderTraversal(ptr->left); //�������� �̵�
		postorderTraversal(ptr->right); // ���������� �̵�
		printf("[%d] ",ptr->key); // key�� ���
	}
}


int insert(Node* head, int key)
{
	
	Node *node = (Node*)malloc(sizeof(Node)); // �� ��� ����
	node->key = key; // �� ����� key���� �Է¹��� key�� ����
	node->left = NULL; // ���� ��� NULL�� ����
	node->right = NULL; // ������ ��� NULL�� ����
	
	if(head->left == NULL) // ��Ʈ��尡 ����ִٸ�
	{
		head->left = node; // �� ��带 ��Ʈ���� ����
		return 1;
	}
	
	Node *n = head->left; //����ü ������ ����, ��Ʈ��带 ����Ŵ, Ʈ���� Ž���ϴ� ����

	while (n!= NULL) // n�� NULL�� �ƴ� ��(NULL�� ��� ����)���� �ݺ�
	{
		if (key == n->key) // �Է¹��� key���� �̹� �����Ѵٸ�
		{
			printf("Data is duplicated.\n"); 
			return 1; // �ߺ��� �����Ͷ�� ����ϰ� ����
		}

		if(key < n->key) // �Է¹��� key���� ���� ����� key������ �۴ٸ�
		{
			if(n->left == NULL) // ���� ����� ���� ��尡 ����ִٸ�
			{
				n->left = node; //���� ��忡 �� ��带 �߰�
				return 1;
			}
			else
			{
				n = n->left; // ���� ��尡 ������� �ʴٸ� ���� ���� �̵�
			}	
		}

		if(key > n->key) // �Է¹��� key���� ���� ����� key������ ũ�ٸ�
		{
			if(n->right == NULL) // ���� ����� ������ ��尡 ����ִٸ�
			{
				n->right = node; // ������ ��忡 �� ��带 �߰�
				return 1;
			}
			else
			{
				n = n->right; // ������ ��尡 ������� �ʴٸ� ������ ���� �̵�
			}
		}
	}	
}

int deleteLeafNode(Node* head, int key)
{
	Node *n = head->left; 
	Node *p = head; 

	if(head == NULL) // ����尡 ����ִ� ���
	{
		printf("tree is empty.\n"); 
		return 0; // Ʈ���� ��������� ����ϰ� ����
	}

	if(n == NULL) // ��Ʈ��尡 ����ִ� ���
	{
		printf("tree is empty.\n");
		return 0; // Ʈ���� ��������� ����ϰ� ����
	}

	while(n != NULL) // n�� NULL�� �ƴ� ��(NULL�� ��� ����)���� �ݺ�
	{
		if(n->key == key) // �Է¹��� key ���� ����� ���� ���ٸ�
		{
			if((n->left == NULL) && (n->right == NULL)) // ��������� ���
			{
				if(p->left == n) // �θ����� ���� �ڽ��ϰ��
				{
					p->left = NULL; // �θ����� ���� NULL
					free(n); // �ڽĳ�� ����
					return 0;
				}

				else if(p->right == n) // �θ����� ������ �ڽ��ϰ��
				{
					p->right = NULL; // �θ����� ������ NULL
					free(n); // �ڽĳ�� ����
					return 0;
				}
			}
			else // ������尡 �ƴҰ��
			{
				printf("node is not leafNode.\n");
				return 0;
			}

		}
		
		if(key > n->key) // �Է¹��� key ���� �� ū ���
		{
			p = n; // p�� n�� ��ġ�� �̵�
			n = n->right; //n�� ������ ���� �̵�
		}
			
		else if(key < n->key) // �Է¹��� key ���� �� �������
		{
			p = n; // p�� n�� ��ġ�� �̵�
			n = n->left; // n�� ���� ���� �̵�
		}	
	}
	
	printf("not exist key node in tree.\n"); // �Է¹��� key ���� �ش��ϴ� ��尡 ���� ���
	return 0;

}

Node* searchRecursive(Node* ptr, int key)
{
	if(ptr == NULL) // ��Ʈ��尡 ����ִ� ���
		return NULL; // NULL ����

	if(ptr->key == key) // key ���� �ش��ϴ� ��带 ã�� ���
		return ptr; //�ش� ����� �ּ� ����

	else if(key > ptr->key) // �Է¹��� key ���� �� ū ���
		searchRecursive(ptr->right,key); // ���������� �̵�

	else if(key < ptr->key) // �Է¹��� key ���� �� ���� ���
		searchRecursive(ptr->left,key); // �������� �̵�
}

Node* searchIterative(Node* head, int key)
{
	Node *n = head->left; // ����ü ������ n ���� �� ��Ʈ���� �ʱ�ȭ

	if(n == NULL) // ��Ʈ��尡 ����ִ� ���
		return NULL; // NULL ����

	while(n != NULL) // n�� NULL�� �ƴ� ��(null�� ��� ����)���� �ݺ�
	{
		if(n->key == key) // �Է¹��� key���� �ش��ϴ� ��带 ã����
			return n; // �� ����� �ּ� ����

		if(key > n->key) // �Է¹��� key ���� �� ũ�ٸ�
			n = n->right; // ���������� �̵�

		else if(key < n->key) // �Է¹��� key ���� �� �۴ٸ�
			n = n->left; // �������� �̵�
	}
}


int freeBST(Node* head)
{
	if(head->left == NULL) // ��Ʈ��尡 ������
	{
		free(head); 
		return 1; // ����� �Ҵ� ���� �� ����
	}

	Node* p = head->left; // ��Ʈ���� �����͸� �̵�

	freeNode(p); // Ʈ�� �Ҵ� ����

	free(head); // ����� �Ҵ� ����
	return 1;
}

// Ʈ���� ��� ��带 �����ϴ� �Լ�
void freeNode(Node* ptr) 
{
	if(ptr) // ptr�� ������� �ʴٸ�
	{
		freeNode(ptr->left); // �������� �̵�
		freeNode(ptr->right); // ���������� �̵�
		free(ptr); // ptr ����
	}
}




