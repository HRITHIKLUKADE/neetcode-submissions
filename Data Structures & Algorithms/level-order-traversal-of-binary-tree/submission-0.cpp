class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> finalans;

        while(!q.empty()){

            int size = q.size();
            vector<int> ans;   // Create a new vector for each level

            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();

                ans.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            finalans.push_back(ans);
        }

        return finalans;
    }
};