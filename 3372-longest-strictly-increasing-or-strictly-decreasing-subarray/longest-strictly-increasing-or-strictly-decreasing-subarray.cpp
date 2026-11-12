class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0;i<n;i++){
            int incr = 1;
            int j = i+1;

            while(j<n && nums[j]> nums[j-1]){
                incr ++;
                j++;
            }
            int decr =1;
           

            while(j<n && nums[j]< nums[j-1]){
                decr++;
                j++;
            }
            result = max({result, decr, incr});
        }
        return result;
    }
};