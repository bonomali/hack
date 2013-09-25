class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if (numbers.size() == 0) return result;
        vector<int> sortedVec(numbers);
        sort(sortedVec.begin(), sortedVec.end());
        int start = 0;
        int end = sortedVec.size() - 1;
        while (start < end){
            if (sortedVec[start] + sortedVec[end] == target)
                break;
            else if (sortedVec[start] + sortedVec[end] > target)
                end--;
            else
                start++;
        }
        for (int i = 0; i < numbers.size(); i++){
            if (numbers[i] == sortedVec[start] || numbers[i] == sortedVec[end])
                result.push_back(i+1);
        }
        return result;
    }
};
