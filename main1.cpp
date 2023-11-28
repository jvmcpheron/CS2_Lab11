#include <iostream>
#include <queue>

namespace std {

    class BinaryNode {
    public:
        int data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    class BinaryTree {
    private:
        BinaryNode* root;

        BinaryNode* insert(BinaryNode* node, int value) {
            if (node == nullptr) {
                return new BinaryNode(value);
            }

            if (value < node->data) {
                node->left = insert(node->left, value);
            } else if (value > node->data) {
                node->right = insert(node->right, value);
            }

            return node;
        }

        void displayTreeHelper(BinaryNode* node, int level) {
            if (node != nullptr) {
                displayTreeHelper(node->right, level + 1);

                for (int i = 0; i < level; ++i) {
                    cout << "    ";
                }

                cout << node->data << endl;

                displayTreeHelper(node->left, level + 1);
            }
        }

    public:
        BinaryTree() : root(nullptr) {}

        void insert(int value) {
            root = insert(root, value);
        }

        void displayTree() {
            displayTreeHelper(root, 0);
            cout << endl;
        }

        void rebalance() {
            root = rebalanceHelper(root);
        }

    private:
        BinaryNode* rebalanceHelper(BinaryNode* node) {

            //base case
            if (node == nullptr || node->right == nullptr) {
                return node;
            }

            
            if (node->right->right != nullptr && node->right->left == nullptr &&
                node->right->right->left == nullptr && node->right->right->right == nullptr) {
                
                BinaryNode* newRoot = node->right;
                node->right = newRoot->left;
                newRoot->left = node;
                return newRoot;
            }

            node->right = rebalanceHelper(node->right);
            return node;
        }
    };
}

int main() {
    std::BinaryTree myTree;
    
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(60);
    myTree.insert(80);

    myTree.displayTree();

    myTree.rebalance();

    myTree.displayTree();

    return 0;
}
