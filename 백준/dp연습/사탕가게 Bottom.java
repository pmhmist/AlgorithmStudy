import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] cal;
    static int[] cost;
    static int[] dp;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while(true){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            double M = Double.parseDouble(st.nextToken());

            // 부동소수점 이슈로 +0.005 해줘야한다.
            if(N == 0 && M == 0.00) break;
            M+=0.005;
            cal = new int[N];
            cost = new int[N];
            double tmp;

            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                cal[i] = Integer.parseInt(st.nextToken());
                tmp = Double.parseDouble(st.nextToken());
                tmp += 0.005;
                cost[i] = (int) (tmp*100);
            }
            int total = (int) (M*100);
            dp = new int[total+1];

            for(int i = 0; i < N; i++){
                int ck = cal[i];
                for(int j = 0; j <= total; j++) {
                    if(j-cost[i] < 0) continue;
                    dp[j] = Math.max(dp[j],dp[j-cost[i]] + ck);
                }
            }
            System.out.println(dp[total]);
        }


    }
}