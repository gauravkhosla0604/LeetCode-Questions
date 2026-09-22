class Solution {
public:
    vector<string> ans;
    vector<string> letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(string& digits,int idx,string curr){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit=digits[idx]-'0';
        for(int i=0;i<letters[digit].size();i++){
            curr.push_back(letters[digit][i]);
            solve(digits,idx+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        solve(digits,0,"");
        return ans;
    }
};