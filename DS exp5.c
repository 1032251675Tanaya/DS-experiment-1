#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

/* Create a new node */
struct node *createNode() {
    struct node *newNode;
    int data;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert a node */
void insert() {
    struct node *current, *temp;

    current = createNode();

    if (root == NULL) {
        root = current;
        printf("Element inserted successfully.\n");
        return;
    }

    temp = root;

    while (1) {
        if (current->data == temp->data) {
            printf("Element already exists.\n");
            free(current);
            return;
        }

        if (current->data < temp->data) {
            if (temp->left == NULL) {
                temp->left = current;
                printf("Element inserted successfully.\n");
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = current;
                printf("Element inserted successfully.\n");
                return;
            }
            temp = temp->right;
        }
    }
}

/* Inorder traversal */
void inorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

/* Preorder traversal */
void preorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if (ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

/* Postorder traversal */
void postorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

/* Clear the tree */
void clearBST(struct node *ptr) {
    if (ptr != NULL) {
        clearBST(ptr->left);
        clearBST(ptr->right);
        free(ptr);
    }
}

/* Search for an element */
void search() {
    int data;
    struct node *temp = root;

    printf("Enter data to search: ");
    scanf("%d", &data);

    while (temp != NULL) {
        if (data == temp->data) {
            printf("Element is found.\n");
            return;
        }

        if (data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    printf("Element is not found.\n");
}

/* Delete a node */
struct node *delete(struct node *root, int data) {
    struct node *temp;

    if (root == NULL)
        return NULL;

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        /* No child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Only right child */
        else if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        /* Only left child */
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Two children */
        else {
            temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

/* Main function */
int main() {
    int choice, data;

    while (1) {
        printf("\n\n...Binary Search Tree...\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Clear BST\n");
        printf("6. Search\n");
        printf("7. Delete Node\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    clearBST(root);
                    root = NULL;
                    printf("Tree cleared successfully.\n");
                }
                break;

            case 6:
                search();
                break;

            case 7:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Deletion operation completed.\n");
                break;

            case 8:
                clearBST(root);
                root = NULL;
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
