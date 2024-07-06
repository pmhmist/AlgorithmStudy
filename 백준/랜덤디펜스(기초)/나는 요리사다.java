import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int no = -1;
        int sum = -1;
        for(int i = 0; i < 5; i++){
            st = new StringTokenizer(br.readLine());
            int tmp = 0;
            for(int j = 0; j < 4; j++){
                tmp += Integer.parseInt(st.nextToken());
            }

            if(sum < tmp){
                sum = tmp;
                no = i+1;
            }

        }

        System.out.println(no + " " + sum);


    }
}