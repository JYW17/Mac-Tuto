//import java.io.BufferedReader;
import java.io.IOException;
//import java.io.InputStreamReader;

//test
public class test{
    public static void main(String args[]) throws IOException{
        int count1, count2, count3, rst;
        rst = 0;
        count1 = count2 = count3 = 5;
        System.out.printf("%d %d %d %d\n", count1, count2, count3, rst);

        count1++;
        rst = -(count2++);
        rst = (-count3)++;
        
        System.out.printf("%d %d %d %d\n", count1, count2, count3, rst);

    }
}