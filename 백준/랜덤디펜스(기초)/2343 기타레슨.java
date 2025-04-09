import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = 0;

        int left = Integer.MIN_VALUE;
        int right = 1_100_000_000;

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if(left < arr[i]) left = arr[i];
        }

        while(left <= right) {
            int mid = (left + right)/2;
            int cnt = 1;
            int sum = 0;

            for (int i = 0; i < n; i++) {
                sum += arr[i];
                if(sum > mid) {
                    sum = arr[i];
                    cnt++;
                }
            }
            if(cnt <= m) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }

        System.out.println(ans);

    }
}
