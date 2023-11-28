#include <iostream>
#include <queue>

using namespace std;
class TreeNode{
   public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data){
      val = data;
      left = right = NULL;
   }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }else{
         q.push(temp->left);
      }
      if(!temp->right){
      if(val != NULL)
         temp->right = new TreeNode(val);
      else
         temp->right = new TreeNode(0);
      return;
      }else{
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
void tree_level_trav(TreeNode*root){
   if (root == NULL) return;
      cout << "[";
      queue<TreeNode *> q;
      TreeNode *curr;
      q.push(root);
      q.push(NULL);
      while (q.size() > 1) {
         curr = q.front();
         q.pop();
         if (curr == NULL){
            q.push(NULL);
      } else {
         if(curr->left)
            q.push(curr->left);
         if(curr->right)
            q.push(curr->right);
         if(curr->val == 0 || curr == NULL){
            cout << "null" << ", ";
         }else{
            cout << curr->val << ", ";
         }
      }
   }
   cout << "]"<<endl;
}
class Solution {
public:
   vector <int> arr;
   void inorder(TreeNode* node){
      if(!node || node->val == 0) return;
      inorder(node->left);
      arr.push_back(node->val);
      inorder(node->right);
   }
   TreeNode* construct(int low, int high){
      if(low > high) return NULL;
      int mid = low + (high - low) / 2;
      TreeNode* root = new TreeNode(arr[mid]);
      root->left = construct(low, mid - 1);
      root->right = construct(mid + 1, high);
      return root;
   }
   TreeNode* balanceBST(TreeNode* root) {
      inorder(root);
      return construct(0, (int)arr.size() - 1);
   }
};


int main(){
   vector<int> v = {1,NULL,2,NULL,NULL,NULL,3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,4};
   TreeNode *root = make_tree(v);
   Solution ob;
   tree_level_trav(ob.balanceBST(root));
}