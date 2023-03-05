class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1)
            return true;
        if(word[0]>='A' && word[0]<='Z'){
            if(word[1]>='A'&& word[1]<='Z'){
                for(int i=1;i<word.size();i++)
                    if(!(word[i]>='A'&& word[i]<='Z'))
                        return false;
            }
            else{
                for(int i=1;i<word.size();i++)
                    if(!(word[i]>='a'&& word[i]<='z'))
                        return false;
            }
        }
        else{
            for(int i=0;i<word.size();i++)
                    if(!(word[i]>='a'&& word[i]<='z'))
                        return false;
        }
        return true;
    }
};