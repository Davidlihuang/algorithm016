#include <stack>
class Solution {
public:
    void helper(int n, int left, int right, string s, vector<string>& res);
    bool isValid(string s);
    void helper2(int level, int max, string s, vector<string>& res);
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        //helper(n, 0, 0, "" ,result);
        helper2(0, 2*n, "", result);
        return result;
    }
};

// 递归剪枝处理
void Solution::helper(int n, int left, int right, string s, vector<string>& res) {
    //terminal condition
    if(left == n && right == n) {
        //if the 
        res.push_back(s);
        return;
    }
    //current level process
    //drill down
    if(left < n) helper(n, left+1, right,s+'(',res);
    if(left > right) helper(n, left, right+1, s+')', res);
    //state  clear 
}
//获取所有的情况
void Solution::helper2(int level, int max, string s, vector<string>& res) {
    //terminal 
    if(level == max) {
        //过滤
        if (isValid(s)) {
            res.push_back(s);
        }
        return;
    }
    //process
    string s1 = "(";
    string s2 = ")";
    //drill down
    helper2(level+1, max, s + s1, res);
    helper2(level+1, max, s + s2, res);
    //clear states
}
bool Solution::isValid(string str) {
    /*
    *1、遇到左括号，入栈
    *2、遇到右括号，当前栈不为空则出栈，否则括号匹配出错
    *3、最后栈为空，说明括号全部匹配。否则括号匹配出错
    */
    if(str.size() == 0) return false;
    int length = str.size();
    std::stack<char> st;
    
    for(int i = 0; i< length; i++) {
        
        if(str[i] == '(') {
            st.push(str[i]);
        } else {
            if(!st.empty()) {
                st.pop();
            } else {
                return false;
            }    
        }
    }
    if(!st.empty()) return false;
    return true;
}