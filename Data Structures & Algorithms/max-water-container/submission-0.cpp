class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
         int j=heights.size()-1;

         int ans=INT_MIN;


         while(i<j){
            int x = min(heights[i],heights[j]);
            int y=j-i;

            ans=max(ans,abs(x)*y);
            if (heights[i] < heights[j])
                i++;
            else
                j--;

         }
         return ans;

    }
};
