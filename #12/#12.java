class Solution {
    public String intToRoman(int nums) {
        String [] roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        String ans="";
        int [] integer = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        for(int i=integer.length-1;i>-1;i--){
            while(nums!=0 && integer[i]<=nums){
                nums-=integer[i];
                ans+=roman[i];
            }
        }
        return ans;
    }
}