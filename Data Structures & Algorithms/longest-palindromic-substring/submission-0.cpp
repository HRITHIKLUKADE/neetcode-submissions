class Solution {
public:
bool  isPalindrome(string s ){
    int left=0;
    int right=s.size()-1;

    while(left<right){
        if(s[left]!=s[right])
        return false;

        left++;
        right--;

    }
    return true;

}
    string longestPalindrome(string s) {
       int n=s.size();

       string ans="";



       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);

             if (isPalindrome(temp) && temp.size() > ans.size()) {
                    ans = temp;
             }
        }
       } 
       return ans;

    }
};
