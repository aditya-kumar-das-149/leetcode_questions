class Solution {
    public int divide(int divi, int divs) {
        if(divi==Integer.MIN_VALUE && divs==-1){
            return Integer.MAX_VALUE;
        } 
        boolean isNegative = (divi<0)^(divs<0);
        long divident = Math.abs((long) divi);
        long divisor = Math.abs((long) divs);
        long quo=0;
        while(divident>=divisor){
            long tempdiv=divisor,count=1;
            while(divident>=(tempdiv<<1)){
                tempdiv=tempdiv<<1;
                count*=2;
            }
            divident-=tempdiv;
            quo+=count;
        }
        return (isNegative)?(int)(-quo):(int)(quo);
    }
}