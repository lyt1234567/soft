package com.company;
class sumMax{
    public int sunArrayMax(int[] array){
        if(array.length==0)
            return 0;
        int max=0;
        int sum=0;
        for(int i=0;i<array.length;i++){
            sum=sum+array[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }

}
public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] array={-2,11,-4,13,-5,-2};
        sumMax t=new sumMax();
        System.out.println(t.sunArrayMax(array));
    }
}
