class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if (target == A[mid])
                return mid;
            else if (target < A[mid])
                right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
