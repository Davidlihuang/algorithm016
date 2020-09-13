class Solution {
public:
    int climbStairs(int n) {
        int pre =1, midle = 2;
        int result = pre + midle;
        if (n < 3) {
            return n;
        }
        for (int i = 3; i < n; i++) {
            pre =  midle;
            midle = result;
            result = pre + midle;
        }
        return result;
    }
};