//Jane McPheron

/*

EXAMPLES OF SOLUTION


./main
Add node:1
Add node:2
Add node:3
Add node:4
Add node:9
Add node:7
Add node:8
Add node:;
1 
X 2 
X 3 
X 4 
X 9 
7 X 
X 8 
X X 
Tree After Balancing: 
4 
2 8 
1 3 7 9 
X X X X X X X X 

jvmcpheron@dyn-10-140-246-187 CS2_Lab11 % ./main
Add node:10
Add node:9
Add node:8
Add node:11
Add node:21
Add node:54
Add node:;
10 
9 11 
8 X X 21 
X X X 54 
X X 
Tree After Balancing: 
11 
9 21 
8 10 X 54 
X X X X X X 

jvmcpheron@dyn-10-140-246-187 CS2_Lab11 % ./main
Add node:12
Add node:13
Add node:45
Add node:8
Add node:6
Add node:97
Add node:54
Add node:7
Add node:2
Add node:1
Add node:;
12 
8 13 
6 X X 45 
2 7 X 97 
1 X X X 54 X 
X X X X 
Tree After Balancing: 
13 
6 54 
2 8 45 97 
1 X 7 12 X X X X 
X X X X X X 
jvmcpheron@dyn-10-140-246-187 CS2_Lab11 % 


*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

    //node class
    class BinaryNode{
        protected:

            int height;
            int data;
            BinaryNode *left;
            BinaryNode *right;
            BinaryNode(){};
        public:

        // Updated method to update height
            void updateHeight() {
                height = 1 + max((left ? left->getHeight() : 0), (right ? right->getHeight() : 0));
            }

            //constrcutor
            BinaryNode(int d, BinaryNode *lft = nullptr, BinaryNode *rgt = nullptr) {data = d;  left = lft;  right = rgt;  height=1;}
            
            //methods
            int getData() { return data; }
            BinaryNode *getLeft() { return left; }
            BinaryNode *getRight() { return right; }
            void setData(int d) { data = d; }
            void setLeft(BinaryNode *p) { left = p; }
            void setRight(BinaryNode *p) { right = p; }
            int compare(BinaryNode *p) { return p->data - data; }
            int compare(int d) { return d - data; }
            void doPrintFlat(ostream &out);
            void doPrintInOrder(ostream &out, int indent = 0);
            int getHeight() { return height; }




    };


    //tree class
    class BinaryTree{
        private:
            BinaryNode *root;
        public:
            BinaryTree() { root = nullptr; }
            BinaryNode* getRoot() { return root; }
            bool isEmpty() { return (root == nullptr); }
            BinaryNode *find(int d);

            //added insert method
            void insert(int d){ 
                if (isEmpty()) {
                    root = new BinaryNode(d);
                } else {
                    BinaryNode* current = root;
                    bool inserted = false;

                    while (!inserted) {
                        if (d < current->getData()) {
                            if (current->getLeft() == nullptr) {
                                current->setLeft(new BinaryNode(d));
                                inserted = true;
                            } else {
                                current = current->getLeft();
                            }
                        } else if (d > current->getData()) {
                            if (current->getRight() == nullptr) {
                                current->setRight(new BinaryNode(d));
                                inserted = true;
                            } else {
                                current = current->getRight();
                            }
                        } else {
                            // Duplicate values are not allowed
                            // You can modify this part based on your requirements
                            inserted = true;
                        }
                    }
                }
            };

            bool remove(int d);
            void printFlat(ostream &out);
            void printInOrder(ostream &out);
            void printPreOrder(ostream &out, int indent = 0);
            void printPostOrder(ostream &out, int indent = 0);

    };


    //tree class
    class BalancedBinaryTree{
        private:

        //returns height of tree
        int height(BinaryNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(height(node->getLeft()), height(node->getRight()));
        }

        //finds difference between left and right height
        int balanceFactor(BinaryNode *node) {
            if (node == nullptr) {
                return 0;
            }
            return height(node->getLeft()) - height(node->getRight());
        }

        //rotates to the right
        BinaryNode *rotateRight(BinaryNode *y) {
            BinaryNode *x = y->getLeft();
            BinaryNode *T2 = x->getRight();

            x->setRight(y);
            y->setLeft(T2);

            return x;
        }

        //rotates to the left
        BinaryNode *rotateLeft(BinaryNode *x) {
            BinaryNode *y = x->getRight();
            BinaryNode *T2 = y->getLeft();

            y->setLeft(x);
            x->setRight(T2);

            return y;
        }

        BinaryNode *insertHelper(BinaryNode *node, int value) {
            // Perform standard BST insert
            if (node == nullptr) {
                return new BinaryNode(value);
            }

            if (value < node->getData()) {
                node->setLeft(insertHelper(node->getLeft(), value));
            } else if (value > node->getData()) {
                node->setRight(insertHelper(node->getRight(), value));
            } else {
                // Duplicate values are not allowed
                // You can modify this part based on your requirements
                return node;
            }

            // Update height of current node
            node->updateHeight();

            // Get the balance factor to check for rotations
            int balance = balanceFactor(node);

            // Perform rotations if needed to maintain balance
            if (balance > 1) {
                if (value < node->getLeft()->getData()) {
                    // Left-Left Case
                    return rotateRight(node);
                } else {
                    // Left-Right Case
                    node->setLeft(rotateLeft(node->getLeft()));
                    return rotateRight(node);
                }
            } else if (balance < -1) {
                if (value > node->getRight()->getData()) {
                    // Right-Right Case
                    return rotateLeft(node);
                } else {
                    // Right-Left Case
                    node->setRight(rotateRight(node->getRight()));
                    return rotateLeft(node);
                }
            }

            return node;
        }


        BinaryNode *root;
        public:
            BalancedBinaryTree() { root = nullptr; }
            BinaryNode* getRoot() { return root; }
            bool isEmpty() { return (root == nullptr); }
            BinaryNode *find(int d);


            //added sorted insert method
            void insert(int value) {
                root = insertHelper(root, value);
            }

            bool remove(int d);
            void printFlat(ostream &out);
            void printInOrder(ostream &out);
            void printPreOrder(ostream &out, int indent = 0);
            void printPostOrder(ostream &out, int indent = 0);

    };


//print tree
void printTree(BinaryNode n) {
    BinaryNode curr = n;

    //if root is empty, no tree
    if (!curr.getData()) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }



    // Using queue to print tree
    std::queue<BinaryNode*> q;
    q.push(&curr);//add current node to queue

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {

            //go through queue
            BinaryNode* current = q.front();
            q.pop();

            if (current) {
                //display data
                std::cout << current->getData() << " ";

                // add the left and right children to queue
                q.push(current->getLeft());
                q.push(current->getRight());
            } else {
                std::cout << "X "; // Placeholder for null nodes
            }
        }

        std::cout << std::endl;
    }
}




int main(){

 //TEST

    //test tree
    BalancedBinaryTree testTree = BalancedBinaryTree();

    BinaryTree test2Tree = BinaryTree();

    string input = "";

    //input nodes
    while (input != ";"){
        cout << "Add node:";
        cin >> input;

        //stops loop if semicolon
        if(input == ";"){
            break;
        }

        int numIn = stoi(input);

        
        //adds input to tree
        testTree.insert(numIn);
        test2Tree.insert(numIn);
        
    }

    printTree(* test2Tree.getRoot());

    // BinaryTree balancedTree = balanceTheTree(testTree);

    cout << "Tree After Balancing: "<<endl;

    // printTree(*balancedTree.getRoot());
    printTree(*testTree.getRoot());


}