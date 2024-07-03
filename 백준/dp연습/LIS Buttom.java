import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int n;
    static int[] arr;
    static int[] dp;


    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        arr = new int[n+1];
        dp = new int[n+1];
        for(int i = 1; i <= n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i <= n; i++){
            dp[i] = 1;

            for(int j = 1; j < i; j++){
                if(arr[j] < arr[i] && dp[i] < dp[j]+1 ){
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = Math.max(ans,dp[i]);
        }
        System.out.println(ans);

    }
}