class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());  // Sort the array to handle duplicates and improve efficiency
        
        for (int i = 0; i < arr.size() - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int j = i + 1;  // Second pointer
            int k = arr.size() - 1;  // Third pointer
            
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                
                if (sum == 0) {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    
                    // Skip duplicates for the second and third elements
                    while (j < k && arr[j] == arr[j + 1])
                        j++;
                    while (j < k && arr[k] == arr[k - 1])
                        k--;
                    
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;  // Increment second pointer if the sum is less than zero
                } else {
                    k--;  // Decrement third pointer if the sum is greater than zero
                }
            }
        }
        
        return ans;
    }
};
