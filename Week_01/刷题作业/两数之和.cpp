class Solution {
public:
    vector<int> sum(vector<int>& nums, int target);
    vector<int> doubleHashSum(vector<int>& nums, int target);
    vector<int> oneHashSum(vector<int>& nums, int target);
    vector<int> twoSum(vector<int>& nums, int target);
    
};

//暴力解法
vector<int> Solution::sum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
}
//两编哈希
vector<int> Solution::doubleHashSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        //构建哈希表
        for (int i=0; i < nums.size(); i++) {
            index.insert(unordered_map<int, int>::value_type(nums[i], i));
        }
        //查找目标值
        for (int i = 0; i < nums.size(); i++) {
            if (index.count(target-nums[i]) > 0 && index[target-nums[i]] != i) {
               return {i,index[target-nums[i]]};
            }
        }
        return {};
}
//一遍哈希
vector<int> Solution::oneHashSum(vector<int>& nums, int target) {
    unordered_map<int, int> indexMap;
    for(int i=0; i< nums.size(); i++) {
        if(indexMap.find(target-nums[i]) != indexMap.end()) {
            return {indexMap.find(target-nums[i])->second, i};
        }
        indexMap.insert(unordered_map<int, int>::value_type(nums[i], i));
    }
    return { };
}
//执行函数
vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    return oneHashSum(nums, target);
}