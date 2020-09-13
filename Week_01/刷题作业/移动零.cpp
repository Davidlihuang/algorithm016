class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;
        for (int i=0; i< nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
        

       /*Time Limit Exceeded*/
       /*
       int i = 0, j = 0;
       while(i<nums.size()-1) {
           if(nums[i] == 0) {
               for (int j = i; j < nums.size(); j++) {
                   nums[j] = nums[j+1];
               }
               nums[nums.size()-1] = 0;
           } else {
               i++;
           }
       }
       */

      /*
      21/21 cases passed (12 ms)
      Your runtime beats 52.18 % of cpp submissions
      Your memory usage beats 5.48 % of cpp submissions (9.3 MB)
    
      int j =0;
      vector<int> result(nums.size());
      for (int i=0; i<nums.size(); i++) {
          if(nums[i] !=0 ) {
              result[j] = nums[i];
              j++;
          }
      }
      for(int i = 0; i<nums.size(); i++) {
          nums[i] = result[i];
      }
      */
    }
    
};