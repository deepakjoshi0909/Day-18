
class BSTIterator {
private:
    stack<TreeNode*> st;

    void leftMost(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        leftMost(root);
    }
    
    int next() {
        TreeNode* topEle = st.top();
        st.pop();
        if (topEle->right != nullptr) {
            leftMost(topEle->right);
        }
        return topEle->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
