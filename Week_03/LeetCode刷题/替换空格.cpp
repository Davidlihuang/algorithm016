class Solution {
public:
    string replaceSpace(string s) {
         int length = s.size();
         string str = "";
         for(int i = 0; i< length; i++) {
             if(s[i] == ' ') {
                 str += "\%20";
             } else {
                 str += s[i];
             }
         }
         //return str;
         s.replace(" ", "%20");
         return s;
    }
};