/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int solve(MountainArray& mountainArr, int target, int l, int r, bool temp = true) {
        while (l <= r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if (val == target) return m;
            if (temp == val < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int temp = 0, r = mountainArr.length() - 1;
        while (temp < r) {
            int m = (temp + r) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) r = m;
            else temp = m + 1;
        }
        int i = solve(mountainArr, target, 0, temp);
        return i != -1 ? i : solve(mountainArr, target, temp + 1, mountainArr.length() - 1, false);
    }
};
