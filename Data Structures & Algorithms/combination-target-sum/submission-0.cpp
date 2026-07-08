class Solution {
public:

void solve(int i, vector<int>&temp,vector<vector<int>>&ans,vector<int>& nums, int target){
    int n=nums.size();

    if(target==0){
        ans.push_back(temp);
        return;

    }
    if(i==n || target<0){
        return;

    }

    temp.push_back(nums[i]);
        solve(i, temp, ans, nums, target - nums[i]);

    temp.pop_back();
     solve(i + 1, temp, ans, nums, target);

}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, temp, ans, nums, target);

        return ans;
    }
};
