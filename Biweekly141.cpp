Q1
class Solution {
public:
    int findMinCondition(int target) {
        for (int z = 1; z <= target; ++z) {
            if ((z | (z + 1)) == target) {
                return z;
            }
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& values) {
        int length = values.size();
        vector<int> results(length, -1);

        for (int i = 0; i < length; ++i) {
            results[i] = findMinCondition(values[i]);
        }

        return results;
    }
};

Q2
#include <vector>
#include <limits.h>

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            result[i] = findMinimalCandidate(nums[i]);
        }
        
        return result;
    }
    
private:
    int findMinimalCandidate(int number) {
        int minimalResult = INT_MAX;
        bool isFound = false;
        
        for (int bit = 0; bit <= 30; bit++) {
            if (isBitSet(number, bit)) {
                int candidate = unsetBit(number, bit);
                
                if (candidate < 0) continue;
                
                if (isValidCandidate(candidate, number)) {
                    if (candidate < minimalResult) {
                        minimalResult = candidate;
                        isFound = true;
                    }
                }
            }
        }
        
        return isFound ? minimalResult : -1;
    }
    
    bool isBitSet(int number, int position) {
        return (number >> position) & 1;
    }
    
    int unsetBit(int number, int position) {
        return number & ~(1 << position);
    }
    
    bool isValidCandidate(int candidate, int original) {
        return (candidate | (candidate + 1)) == original;
    }
};

Q3.

class Solution {
public:
     int maxRemovals(const std::string& s, const std::string& p, const std::vector<int>& indices) {
        int n = s.length();
        int m = p.length();
        std::vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;
        std::vector<bool> isTarget(n, false);
        
        for (int idx : indices) {
            isTarget[idx] = true;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = m; j > 0; --j) {
                if (s[i] == p[j - 1] && dp[j - 1] != INT_MAX) {
                    dp[j] = std::min(dp[j], dp[j - 1] + (isTarget[i] ? 1 : 0));
                }
            }
        }
        
        return indices.size() - (dp[m] == INT_MAX ? 0 : dp[m]);
    }
};
