class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int check=0;
        int i=digits.size()-1;
        while(check==0){
            if(digits[i]<9){
                digits[i]+=1;
                check=1;
            }
            else{
                digits[i]=0;
                i--;
            }
            if(i<0){
                digits[0]=1;
                for(int i=1;i<digits.size();i++)
                    digits[i]=0;
                digits.push_back(0);
                break;
            }
            
        }
        
        return digits;
    }
};