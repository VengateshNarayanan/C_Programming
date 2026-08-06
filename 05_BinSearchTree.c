#include <stdio.h>
#include <stdlib.h>
// BST Node
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Create a new node
struct Node* createNode(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// Insert into BST
struct Node* insert(struct Node *root, int value)
{
	if(root == NULL)
		return createNode(value);
	if(value < root->data)
		root->left = insert(root->left, value);
	else if(value > root->data)
		root->right = insert(root->right, value);
	return root;
}
// Search element
struct Node* search(struct Node *root, int key)
{
	if(root == NULL || root->data == key)
		return root;
	if(key < root->data)
		return search(root->left, key);
	return search(root->right, key);
}
// Find minimum node
struct Node* minValueNode(struct Node *node)
{
	struct Node *current = node;
	while(current && current->left != NULL)
		current = current->left;
	return current;
}
// Delete node
struct Node* deleteNode(struct Node *root, int key)
{
	if(root == NULL)
		return root;
	if(key < root->data)
		root->left = deleteNode(root->left, key);
	else if(key > root->data)
		root->right = deleteNode(root->right, key);
	else
	{
		// No child
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		// One child
		else if(root->left == NULL)
		{
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct Node *temp = root->left;
			free(root);
			return temp;
		}
		// Two children
		struct Node *temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
// Inorder Traversal
void inorder(struct Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
// Preorder Traversal
void preorder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
// Postorder Traversal
void postorder(struct Node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main()
{
	struct Node *root = NULL;
	int choice, value;
	while(1)
	{
		printf("\n------ Binary Search Tree ADT ------\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Delete\n");
		printf("4. Inorder Traversal\n");
		printf("5. Preorder Traversal\n");
		printf("6. Postorder Traversal\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				root = insert(root, value);
				printf("Node inserted successfully.\n");
				break;
			case 2:
				printf("Enter value to search: ");
				scanf("%d", &value);
				if(search(root, value))
					printf("%d found in BST.\n", value);
				else
					printf("%d not found.\n", value);
				break;
			case 3:
				printf("Enter value to delete: ");
				scanf("%d", &value);
				root = deleteNode(root, value);
				printf("Deletion completed.\n");
				break;
			case 4:
				printf("Inorder Traversal: ");
				inorder(root);
				printf("\n");
				break;
			case 5:
				printf("Preorder Traversal: ");
				preorder(root);
				printf("\n");
				break;
			case 6:
				printf("Postorder Traversal: ");
				postorder(root);
				printf("\n");
				break;
			case 7:
				printf("Program terminated.\n");
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}
