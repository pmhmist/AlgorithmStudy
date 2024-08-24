import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        while(c-- > 0){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(a == b){
                sb.append(1).append('\n');
            }
            else if(a < b){
                int tmp = b-1;
                int round = k - b;
                if(a + round < tmp){
                    sb.append(0).append('\n');
                }
                else{
                    sb.append(1).append('\n');
                }
            }
            else{
                int tmp = a-1;
                int round = k - a;
                if(b + round + 1 < tmp){
                    sb.append(0).append('\n');
                }
                else{
                    sb.append(1).append('\n');
                }
            }

        }
        System.out.println(sb);

    }
}