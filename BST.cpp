
#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node *left, *right;

    Node(int value) {
        rollNo = value;
        left = right = nullptr;
    }
};

// Insert a student record
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->rollNo)
        root->left = insert(root->left, value);
    else if (value > root->rollNo)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate roll number!\n";

    return root;
}

// Search for a student
Node* search(Node* root, int key) {
    if (root == nullptr || root->rollNo == key)
        return root;

    if (key < root->rollNo)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum key
Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

// Find maximum key
Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

// Find predecessor (largest key smaller than given key)
Node* predecessor(Node* root, int key) {
    Node* pred = nullptr;

    while (root != nullptr) {
        if (key > root->rollNo) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return pred;
}

// Find successor (smallest key larger than given key)
Node* successor(Node* root, int key) {
    Node* succ = nullptr;

    while (root != nullptr) {
        if (key < root->rollNo) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return succ;
}

// Delete a student record
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->rollNo) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->rollNo) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No left child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->rollNo = temp->rollNo;
        root->right = deleteNode(root->right, temp->rollNo);
    }

    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->rollNo << " ";
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->rollNo << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->rollNo << " ";
    }
}

// Free allocated memory
void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int choice, rollNo;

    do {
        cout << "\n\n===== STUDENT RECORD BST =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Find Minimum Roll Number\n";
        cout << "3. Find Maximum Roll Number\n";
        cout << "4. Search Student\n";
        cout << "5. Find Predecessor\n";
        cout << "6. Find Successor\n";
        cout << "7. Delete Student\n";
        cout << "8. Inorder Traversal\n";
        cout << "9. Preorder Traversal\n";
        cout << "10. Postorder Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number: ";
                cin >> rollNo;
                root = insert(root, rollNo);
                break;

            case 2: {
                Node* temp = findMin(root);
                if (temp)
                    cout << "Minimum roll number: "
                         << temp->rollNo;
                else
                    cout << "BST is empty!";
                break;
            }

            case 3: {
                Node* temp = findMax(root);
                if (temp)
                    cout << "Maximum roll number: "
                         << temp->rollNo;
                else
                    cout << "BST is empty!";
                break;
            }

            case 4: {
                cout << "Enter roll number to search: ";
                cin >> rollNo;
                Node* temp = search(root, rollNo);

                if (temp)
                    cout << "Student found: " << temp->rollNo;
                else
                    cout << "Student not found!";
                break;
            }

            case 5: {
                cout << "Enter roll number: ";
                cin >> rollNo;

                Node* temp = predecessor(root, rollNo);

                if (temp)
                    cout << "Predecessor: " << temp->rollNo;
                else
                    cout << "No predecessor exists!";
                break;
            }

            case 6: {
                cout << "Enter roll number: ";
                cin >> rollNo;

                Node* temp = successor(root, rollNo);

                if (temp)
                    cout << "Successor: " << temp->rollNo;
                else
                    cout << "No successor exists!";
                break;
            }

            case 7:
                cout << "Enter roll number to delete: ";
                cin >> rollNo;

                if (search(root, rollNo)) {
                    root = deleteNode(root, rollNo);
                    cout << "Student deleted successfully!";
                } else {
                    cout << "Student not found!";
                }
                break;

            case 8:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 9:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 10:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 0:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }
    } while (choice != 0);

    freeTree(root);
    return 0;
}
