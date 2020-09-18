/*题目描述
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * 输入: 38
 * 输出: 2 
 * 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
 * */
class Solution {
public:
    int addDigits(int num) {
    //暴力
    int temp=num;
    
    while (temp/10){
        int sum = 0;
        while(temp != 0){
            sum = sum + temp%10;
            temp /= 10;
        }
        temp = sum;
    }
    
    //公式
    if (num == 0) 
         return num;
    if (num % 9 == 0) 
        return 9;
    else 
        return num % 9;

    return temp;
    }
};