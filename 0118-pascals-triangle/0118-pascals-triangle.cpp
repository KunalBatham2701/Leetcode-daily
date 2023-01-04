class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vector<int> v;
        v.push_back(1);
        vec.push_back(v);
        for(int i=1;i<numRows;i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j=0;j<v.size()-1;j++){
                v1.push_back(v[j]+v[j+1]);
            }
            v1.push_back(1);
            v.clear();
            v=v1;
            vec.push_back(v1);
        }
        return vec;
    }
};