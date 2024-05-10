class Solution {
public:
    int trap(const std::vector<int> &height) {
        if (height.empty()) {
            return 0;
        }

        int H = height.size();
        int res = 0;

        std::vector<int> leftMax(H);
        std::vector<int> rightMax(H);

        // 왼쪽에서부터 최대 높이 저장
        leftMax[0] = height[0];
        for (int i = 1; i < H; ++i) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        // 오른쪽에서부터 최대 높이 저장
        rightMax[H - 1] = height[H - 1];
        for (int i = H - 2; i >= 0; --i) {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        // 물을 잡을 수 있는 양 계산
        for (int i = 0; i < H; ++i) {
            res += std::min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
};