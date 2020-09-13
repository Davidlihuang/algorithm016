class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //法一： 双指针；
        //1、使用一个快指针和慢指针，快指针遍历所有的元素
        //2、当slowPointer 和 quickPointer的值不相等时，将quickPointer处的值覆盖slowPointer+1处的值
        //   然后slowPointer+1；
        int slow = 0;
        if(nums.size() < 2) return nums.size();
        for (int quick = 1; quick < nums.size(); quick++) {
            if(nums[quick] != nums[slow]) {
                if(quick - slow > 1) {
                    nums[slow+1] = nums[quick];
                }
                slow++;
            }
        }
        return slow+1;
        
        //法二： 
        //1、使用unique去重。返回不重复序列的下一个位置的迭代器
        //2、使用erase(begin,end)，删除nums尾部无效的数据
        //return nums.erase(unique(nums.begin(), nums.end()), nums.end()) - nums.begin();
    }
};