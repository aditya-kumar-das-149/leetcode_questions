class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        StringBuilder[] sbs =new StringBuilder[Math.min(numRows,s.length())];
        for(int i=0; i<sbs.length;i++){
            sbs[i] = new StringBuilder(); 
        }
        boolean goingDown = false;
        int currentRow=0;
        for(char c:s.toCharArray()){
            sbs[currentRow].append(c);
            if(currentRow==0 || currentRow==numRows-1){
                goingDown=!goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }
        StringBuilder result = new StringBuilder();
        for(StringBuilder row:sbs){
            result.append(row.toString());
        }
        
        return result.toString();
        
    }
}