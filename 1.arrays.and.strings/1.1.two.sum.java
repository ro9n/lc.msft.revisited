class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (m.containsKey(target - nums[i])) {
                return new int[] { m.get(target - nums[i]), i };
            }
            m.put(nums[i], i);
        }

        return new int[] { -1, -1 };
    }
}