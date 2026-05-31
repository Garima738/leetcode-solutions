class Solution {
public:
    char findTheDifference(string s, string t) {
        int length = s.size();

        
        char s_array[1000];  
        for(int i = 0; i < length; i++) {
            s_array[i] = s[i];
        }

       
        for(int i = 0; i < t.size(); i++) {
            bool matchFound = false; 

           
            for(int j = 0; j < length; j++) {
                if(s_array[j] == t[i]) {
                    s_array[j] = 0; 
                    matchFound = true;
                    break;  
                }
            }

            
            if(!matchFound) {
                return t[i];
            }
        }

       
        return ' ';
    }
};
