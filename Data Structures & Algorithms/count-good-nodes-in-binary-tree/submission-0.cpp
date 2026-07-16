class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            int mxtillnow = q.front().second;
            q.pop();

            if (temp->val >= mxtillnow)
                count++;

            mxtillnow = max(mxtillnow, temp->val);

            if (temp->left)
                q.push({temp->left, mxtillnow});

            if (temp->right)
                q.push({temp->right, mxtillnow});
        }

        return count;
    }
};