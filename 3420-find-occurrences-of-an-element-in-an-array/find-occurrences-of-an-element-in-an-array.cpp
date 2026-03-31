class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            indices.push_back(i);
        }
    }

    vector<int> answer;

    for (int q : queries) {
        if (q <= indices.size()) {
            answer.push_back(indices[q - 1]);
        } else {
            answer.push_back(-1);
        }
    }

    return answer;
    }
};