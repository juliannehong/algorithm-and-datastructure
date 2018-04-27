//https://leetcode.com/problems/combination-sum/description/

void dp(unordered_map<int, set<int>>& m, const vector<int>& candidates, int target) {

}

vector<vector<int>> combination_sum(const vector<int>& candidates, int target) {
  unordered_map<int, set<set<int>>> m;
  m[target].insert({});
  for (auto c : candidates)
    m[c] = { {c} };

  for (int i = 0; i < candidates.size(); i++) {
    if (candidates[i] > target)
      continue;
    int complement = target - candidates[i];
    if (m.find(complement) != m.end()) {
      for (auto s : m[complement]) {
        s.insert(candidates[i]);
      }
    } 
  }
}
