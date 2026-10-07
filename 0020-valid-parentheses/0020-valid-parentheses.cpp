class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(char ch:s){
        if(ch=='(' ||  ch=='{' || ch=='['){
            st.push(ch);
            continue;
 }
         if (st.empty()) {
                return false;
            }
        int topBracket = st.top();
        if( ch == ')' && topBracket!='('){
            return false;
        }
         if( ch == '}' && topBracket!='{'){
            return false;
        }
         if( ch == ']' && topBracket!='['){
            return false;
        }
     st.pop();

        }
        return st.empty();
    }
};