class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> left(n);
        vector<int> right(n);
        
        // 1. Fill the prefix (left) array
        left[0] = 1; // Base case: nothing to the left of the first element
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        // 2. Fill the suffix (right) array
        right[n - 1] = 1; // Base case: nothing to the right of the last element
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        
        // 3. Construct the final output
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
};