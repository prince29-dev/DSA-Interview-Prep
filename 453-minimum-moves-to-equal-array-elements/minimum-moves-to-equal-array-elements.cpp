class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n = nums.size();

       int sum = accumulate(begin(nums),end(nums),0);
       int minE = *min_element(begin(nums),end(nums));

       return sum - n*minE;
    }
};