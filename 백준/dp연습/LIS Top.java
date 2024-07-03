import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int n;
    static int[] arr;
    static int[] dp;

    public static int solve(int n){
        if(dp[n] == 0){
            dp[n] = 1;
            for(int i = n-1; i >= 1; i--){
             if(arr[i] < arr[n]) {
                 dp[n] = Math.max(dp[n],solve(i) + 1);
             }
            }
        }
        return dp[n];
    }


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

        int ans = 0;
        for(int i = 1; i <= n; i++){
            solve(i);
        }

        for(int i = 1; i <= n; i++){
            ans = Math.max(ans,dp[i]);
        }
        System.out.println(ans);

    }
}