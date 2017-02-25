 #include <climits>
 bool is_a_binary_tree(Node* node, int min, int max)
 {
   if(!node) return true;

   bool isBinaryLeft, isBinaryRight;

   isBinaryLeft = is_a_binary_tree(node->left, min, node->data);
   isBinaryRight = is_a_binary_tree(node->right, node->data, max);

   return isBinaryLeft && isBinaryRight && node->data > min && node->data < max;
 }

 bool checkBST(Node* root) {
   return is_a_binary_tree(root, INT_MIN, INT_MAX);
 }