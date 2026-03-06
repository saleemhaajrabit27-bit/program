Majority Element:

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n/2];
    }
}

 Number of 1 Bits:

class Solution {
    public int hammingWeight(int n) {
        int count = 0 ;
        while(n != 0 ) {
            if((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
}