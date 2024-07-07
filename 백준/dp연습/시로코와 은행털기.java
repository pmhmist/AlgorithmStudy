import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static int[] arr;
    static boolean[][] dp;

    public static void solve(int p, int k, int x){
        for(int i = k-1; i >= 1; i--) {
            for(int j = x*k; j >= p; j--) {
                dp[i+1][j] = dp[i+1][j] || dp[i][j-p];
            }
        }
        dp[1][p] = true;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        arr = new int[n];
        dp = new boolean[k+1][x*k+1];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr[i] = a;
        }

        for(int ck : arr){
            solve(ck,k,x);
        }
        int ans = 0;

        for(int i = 0; i <= x*k; i++) {
            if(dp[k][i]) {
                ans = Math.max(ans, i*(x*k-i));
            }
        }


        System.out.println(ans);

    }
}