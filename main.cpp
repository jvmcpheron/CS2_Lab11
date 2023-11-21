//Jane McPheron

/*

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

    //node class
    class BinaryNode{
        protected:
            int data;
            BinaryNode *left;
            BinaryNode *right;
            BinaryNode(){};
        public:
            //constrcutor
            BinaryNode(int d, BinaryNode *lft = nullptr, BinaryNode *rgt = nullptr) {data = d;  left = lft;  right = rgt;  }
            
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


//print tree
void printTree(BinaryNode n) {
    BinaryNode curr = n;
    if (!curr.getData()) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }



    // Using level order traversal to print the tree
    std::queue<BinaryNode*> q;
    q.push(&curr);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            BinaryNode* current = q.front();
            q.pop();

            if (current) {
                std::cout << current->getData() << " ";

                // Enqueue the left and right children
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
    BinaryTree testTree = BinaryTree();

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
        
    }


}