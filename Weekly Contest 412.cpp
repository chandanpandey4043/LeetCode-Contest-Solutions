Q1

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            int min_index = search_min(nums);
            nums[min_index] *= multiplier;
        }
        return nums;
    }

private:
   
    int search_min(vector<int>& nums) {
        int min_index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[min_index]) {
                min_index = i;
            }
        }
        return min_index;
    }
};


Q2

class Solution {
public:
    bool isValidPair(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        
        while (strA.length() < strB.length()) {
            strA = "0" + strA;
        }
        while (strB.length() < strA.length()) {
            strB = "0" + strB;
        }
        
        int mismatchCount = 0;
        int firstMismatchIndex = -1;
        int secondMismatchIndex = -1;
        
        for (int i = 0; i < strA.length(); ++i) {
            if (strA[i] != strB[i]) {
                ++mismatchCount;
                if (mismatchCount == 1) {
                    firstMismatchIndex = i;
                } else if (mismatchCount == 2) {
                    secondMismatchIndex = i;
                } else {
                    return false;
                }
            }
        }
        
        if (mismatchCount == 2) {
            swap(strA[firstMismatchIndex], strA[secondMismatchIndex]);
            return strA == strB;
        }
        
        return false;
    }

    int countPairs(vector<int>& nums) {
        int size = nums.size();
        int validPairsCount = 0;
        
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] == nums[j] || isValidPair(nums[i], nums[j])) {
                    ++validPairsCount;
                }
            }
        }
        
        return validPairsCount;
    }
};
