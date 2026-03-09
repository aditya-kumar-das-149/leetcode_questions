class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int[] merged = new int[n1 + n2];
        int i = 0, j = 0, m = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                merged[m++] = nums2[j++];
            } else {
                merged[m++] = nums1[i++];
            }
        }
        while (i < n1) merged[m++] = nums1[i++];
        while (j < n2) merged[m++] = nums2[j++];
        int totalLength = merged.length;
        if (totalLength % 2 == 1) {
            return merged[totalLength / 2];
        } else {
            return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
        }
    }
}