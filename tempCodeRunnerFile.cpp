     }

    int trap(vector<int>& height) {
        vector<int> original = height;
        int n = height.size();
        vector<int> suffixMaxx = suffixMax(original, original.size());
        vector<int> prefixMaxx = prefixMax(original, original.size());
        int total = 0;
        for (int i = 0; i < n; i++) {
            int leftmax = prefixMaxx[i];
            int rightmax = suffixMaxx[i];
            if (height[i] < leftmax && height[i] < rightmax) {
                total += (min(rightmax, leftmax)-height[i]);
            }
        }
        return total;
    }