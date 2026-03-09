class Solution {
    public int reverse(int x) {
        boolean isNegative = x<0;
        long b = Math.abs((long)x);
        StringBuilder val = new StringBuilder(String.valueOf(b));
        val.reverse();
        long a = Long.parseLong(val.toString());
        if(isNegative) a *= -1;
        if(a<Integer.MIN_VALUE || a>Integer.MAX_VALUE){
            return 0;
        } 
        return (int) a;
    }
}