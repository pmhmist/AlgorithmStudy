import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] arr;
    static int[][] dp;
    static int[] W;
    static int[] V;

    public static int solve(int n, int w){

        if(n < 0) return 0;

        if(dp[n][w] == 0){

            if(w < W[n]){
                dp[n][w] = solve(n-1,w);
            }
            else{
                dp[n][w] = Math.max(solve(n-1,w),V[n] + solve(n-1,w-W[n]));
            }
        }
        return dp[n][w];
    }



    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        W = new int[N];
        V = new int[N];
        dp = new int [N][K+1];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            W[i] = Integer.parseInt(st.nextToken());
            V[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve(N-1,K));

    }
}