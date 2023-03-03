class Solution {
public:
    int strStr(string haystack, string needle) {
         int check;
        for(int i=0;i<haystack.size();i++)
            if(haystack[i]==needle[0]){
                check=0;
                for(int j=0;j<needle.size();j++){
                    if(needle[j]!=haystack[i+j]){
                        check=1;
                        break;
                    }
                }
                if(check==0)
                    return i;
            }
        return -1;
    }
};