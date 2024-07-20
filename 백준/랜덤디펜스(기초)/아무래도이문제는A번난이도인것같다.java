import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public StringBuilder sb = new StringBuilder();



    A에서 *(-1)*(-1)*1을 해서 1을 빼거나, *1을 해서 1을 더할 수 있으므로 무조건 yes를 출력하면 됩니다.
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for(int turn = 0; turn < t; turn++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            System.out.println("yes");

        }


        
    }
}