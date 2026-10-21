class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long cursum = 0;
        long long result = 0;
        int i=0,j=0; 
        unordered_set<int>st;
        while(j<n){
           while(st.count(nums[j])) {
            st.erase(nums[i]);
            cursum -= nums[i];
            i++;
           }
           cursum += nums[j];
           st.insert(nums[j]);

           if(j-i+1==k){
            result = max(result,cursum);
            st.erase(nums[i]);
            cursum -= nums[i];
            i++;
           }
           j++;

        }
        return result;
    }
};