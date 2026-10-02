class Solution {
public:
void func(int index,vector<vector<string>>& res, vector<string>& path,string s){
    if(index==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,res,path,s);
            path.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,res,path,s);
        return res;

        
    }
    bool ispalindrome(string s , int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
        


    }
};