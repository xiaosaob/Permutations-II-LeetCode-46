// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        vector<bool> used(num.size(), false);
        vector<int> sol;
        helper(num, used, sol, res);
        return res;
    }
    
    void helper(vector<int> &num, vector<bool> &used, vector<int> &sol, vector<vector<int> > &res) {
        if(sol.size()== num.size()) {
            res.push_back(sol);
            return;
        }
        for(int i = 0; i < num.size(); ++i) {
            if(used[i]) continue;
            if(i > 0 && num[i] == num[i-1] && used[i-1]) return;
            used[i] = true;
            sol.push_back(num[i]);
            helper(num, used, sol, res);
            sol.pop_back();
            used[i] = false;
        }
    }
};
