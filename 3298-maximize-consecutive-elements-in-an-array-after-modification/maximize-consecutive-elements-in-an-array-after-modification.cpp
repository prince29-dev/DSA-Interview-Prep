class Solution {
public:
int n ;
    vector<vector<int>> memo;
    int findmethod(vector<int>& nums , int start , int target ){
        int j = lower_bound(begin(nums) + start , end(nums), target) - begin(nums);

        if(j<n && nums[j]== target){
            return j;
        }
        return -1;
    }
    int solve(int i , int inc , vector<int>& nums){
        if(memo[i] [inc]!= -1){
            return memo[i] [inc];
            
            
        }

        int currval = nums[i] + inc; // 0 ya 1 
        int len = 1;
// 1st option hai find(currval +1)
        int j = findmethod(nums, i+1 , currval +1);
        if(j!=-1){
          len = max(len , 1 + solve(j, 0, nums));
        }
// 2nd option hai find(currval ) and then inc +1 krege 
           j = findmethod(nums, i+1 , currval );
        if(j!=-1){
          len = max(len , 1 + solve(j, 1, nums));
        }
        return  memo[i] [inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
      
        n = nums.size();

        int result = 1;
        sort(begin(nums),end(nums));
        memo.assign(n+1, vector<int>(2,-1));

        for(int i=0;i<n;i++){
            result = max({result, solve(i, 0 , nums),solve(i,1, nums)});
        }
        return result;
    }
};