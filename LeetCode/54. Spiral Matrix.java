//https://leetcode.com/problems/spiral-matrix/
class Pair{
    int r, c;
    Pair(int r, int c){
        this.r = r;
        this.c = c;
    }
}

class Solution {
     public List<Integer> getOutsideSpiralOrder(Pair leftTop, Pair rightBottom, int[][] matrix){
        List<Integer> order = new ArrayList<>();

        for(int c = leftTop.c; c< rightBottom.c ; ++c)
            order.add(matrix[leftTop.r][c]);

        for(int r = leftTop.r; r<= rightBottom.r ; ++r )
            order.add(matrix[r][rightBottom.c]);

        if(leftTop.r == rightBottom.r || leftTop.c == rightBottom.c)
            return order;

        for(int c = rightBottom.c -1; leftTop.c < c ; --c)
            order.add(matrix[rightBottom.r][c]);

        for(int r = rightBottom.r; leftTop.r < r ; --r)
            order.add(matrix[r][leftTop.c]);

        return order;
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        int row = matrix.length;
        int column = matrix[0].length;
        List<Integer> linkedOrders = new ArrayList<>();

        Pair leftTop = new Pair(0,0);
        Pair rightBottom = new Pair(row -1, column -1);

        while(leftTop.r <= rightBottom.r && leftTop.c <= rightBottom.c){
            linkedOrders.addAll(getOutsideSpiralOrder(leftTop,rightBottom,matrix));
            leftTop.r++; leftTop.c++;
            rightBottom.r --; rightBottom.c--;
        }

        return linkedOrders;
    }
}
