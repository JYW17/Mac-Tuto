import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//test
public class test{
    public static void main(String args[]) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int sugar = Integer.parseInt(bf.readLine());
        int result = 0;

        while (sugar >= 0){
            if (sugar % 5 == 0){
            result += sugar/5;
            System.out.println(result);
            break;
            }
            sugar -= 3;
            result += 1;
        
        }
        if (sugar < 0){
            System.out.println(-1);
        }
    }
}