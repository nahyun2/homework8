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

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------[최나현]-----[2023041039]-----------------------\n");
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

/* 트리 초기화 */
int initializeBST(Node** h) { 

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) // 트리가 비어있지 않다면
		freeBST(*h); // 트리에 할당된 모든 노드를 할당 해제

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); // 헤드 노드 생성
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}


/*중위 순회*/
void inorderTraversal(Node* ptr) 
{
	if(ptr != NULL) // ptr이 비어있지 않으면
	{
		inorderTraversal(ptr->left); // 왼쪽으로 이동
		printf(" [%d] ",ptr->key); // key값 출력
		inorderTraversal(ptr->right); // 오른쪽으로 이동
	}
}

/*전위 순회*/
void preorderTraversal(Node* ptr)
{
	if(ptr != NULL) // ptr이 비어있지 않다면
	{
		printf("[%d] ",ptr->key); // key값 출력
		preorderTraversal(ptr->left); // 왼쪽으로 이동
		preorderTraversal(ptr->right); // 오른쪽으로 이동
	}
}

/*후위 순회*/
void postorderTraversal(Node* ptr)
{
	if(ptr != NULL) // ptr이 비어있지 않다면
	{
		postorderTraversal(ptr->left); //왼쪽으로 이동
		postorderTraversal(ptr->right); // 오른쪽으로 이동
		printf("[%d] ",ptr->key); // key값 출력
	}
}


int insert(Node* head, int key)
{
	
}

int deleteLeafNode(Node* head, int key)
{

}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}


int freeBST(Node* head)
{
	
}





