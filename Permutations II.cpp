//Becasue it contains duplicates, do not choose the element when it's same as the former one.
class Solution {
public:
    void subPermute(vector<int> &num, vector<bool> flag, vector<vector<int>> &result, vector<int> &tmp){
    
    if(tmp.size() == num.size())
        result.push_back(tmp);
    
    else{
        
        int before = 0;
        bool count = false;
        for(int i = 0; i < flag.size(); i++){
            if(!flag[i]){
                if(!count || (count && before != num[i])){
                    count = true;
                    tmp.push_back(num[i]);
                    flag[i] = true;
                    subPermute(num, flag, result, tmp);
                    before = num[i];
                    flag[i] = false;
                    tmp.pop_back();
                    
                }
            }
        }

    }
   
}
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int>> result;
    vector<bool> flag(num.size(), false);
    vector<int> tmp;
    
    sort(num.begin(), num.end());
    
    subPermute(num,flag, result,tmp);
    return result;
}
};
