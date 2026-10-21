class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int n = nums.size();
      int count = 0;
      int maxl = 0;
      int i = 0;
      int j = 0;
      while(j<n){
        if(nums[j]==1){
            count++;
        }
        if(nums[j]==0){
            count = 0;
        }
        maxl = max(maxl,count);
        j++;
      }
      return maxl;
    }
};