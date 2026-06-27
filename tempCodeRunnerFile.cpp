    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n - 1;
        int max_area = 0;

        while (low<high) {
            int area = (high - low + 1) * min(height[low], height[high]);
            if (height[low] <= height[high]) {
                low++;
            } else {
                high--;
            }
            max_area = max(max_area, area);
        } 
        return max_area;
    }