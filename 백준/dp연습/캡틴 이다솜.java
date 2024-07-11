import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int len = 0;
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[300];
        int[] dp = new int[n + 1];

        for (int i = 1; i <= 300; i++) {
            arr[i - 1] = (i * (i + 1)) / 2;
            if (i != 1) arr[i - 1] += arr[i - 2];
            if (arr[i - 1] > n) break;
            len++;
        }

        for (int i = 0; i <= n; i++) {
            dp[i] = 100000000;
        }

        for (int i = 0; i < len; i++) {
            dp[arr[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < len; j++) {
                int tmp = i - arr[j];
                if (tmp < 0) break;
                dp[i] = Math.min(dp[i], dp[tmp] + 1);
            }
        }

        System.out.println(dp[n]);
    }
}