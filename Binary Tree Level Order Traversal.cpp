class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; 
        
        queue<TreeNode*> pq;
        vector<vector<int>> ans;

        pq.push(root);
        while (!pq.empty()) {
            int levelSize = pq.size(); 
            vector<int> step;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = pq.front();
                pq.pop();
                step.push_back(temp->val);

                if (temp->left) pq.push(temp->left);
                if (temp->right) pq.push(temp->right);
            }

            ans.push_back(step);
        }

        return ans;
    }
};
