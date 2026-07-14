class Solution {
public:

int solve(int i,vector<int>& coins, int amount){
    int n=coins.size();

    if(amount==0)
    return 0;
    

    if(i>=n || amount<0)
    return 1e9;

    int take = 1+ solve(i,coins,amount-coins[i]);

    int not_take = solve(i+1,coins,amount);

    return min(take,not_take);



}
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(0,coins,amount);
        if (ans == 1e9)
            return -1;

        return ans;
    }
};
