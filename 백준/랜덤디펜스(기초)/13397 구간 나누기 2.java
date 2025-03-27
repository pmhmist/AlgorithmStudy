import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n,m;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0;
        int right = 10010;
        int ans = 0;

        while(left <= right) {
            int mid = (left + right)/2;
            int cnt = 1;
            int mx = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if(mx < arr[i]) mx = arr[i];
                if(min > arr[i]) min = arr[i];

                if(mx - min > mid) {
                    cnt++;
                    mx = arr[i];
                    min = arr[i];
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
