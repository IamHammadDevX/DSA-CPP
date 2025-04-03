#include<iostream>
#include<vector>
using namespace std;

// main logic
void solve(vector<int> nums, vector<int> output, int idx, vector<vector<int>>& ans) {

    // base case
    if (idx >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // recursive calls
    // Exclude case
    solve(nums, output, idx + 1, ans);

    // include case
    int element = nums[idx];
    output.push_back(element);
    solve(nums, output, idx + 1, ans);

}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> output;
    int idx = 0;
    solve(nums, output, idx, ans);

    return ans;

}

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };  // Example input
    vector<vector<int>> result = subsets(nums);

    // Printing the subsets
    for (int i = 0; i < result.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
