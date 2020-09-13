class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //��һ�� ˫ָ�룻
        //1��ʹ��һ����ָ�����ָ�룬��ָ��������е�Ԫ��
        //2����slowPointer �� quickPointer��ֵ�����ʱ����quickPointer����ֵ����slowPointer+1����ֵ
        //   Ȼ��slowPointer+1��
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
        
        //������ 
        //1��ʹ��uniqueȥ�ء����ز��ظ����е���һ��λ�õĵ�����
        //2��ʹ��erase(begin,end)��ɾ��numsβ����Ч������
        //return nums.erase(unique(nums.begin(), nums.end()), nums.end()) - nums.begin();
    }
};