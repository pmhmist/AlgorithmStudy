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
        long ans = 0;

        long[] arr = new long[m+1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= m; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        if(n <= m) {
            System.out.println(n);
        }
        else {
            n -= m;
            long left = 1;
            long right = 2_000_000_000_000_000L;
            long result = 0;

            while(left <= right) {
                long mid = (left + right) / 2;
                long cnt = 0;

                for(int i = 1; i <= m; i++) {
                    cnt += mid/arr[i];
                }

                if(n <= cnt) {
                    result = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            long cnt1 = 0;
            long cnt2 = 0;

            for(int i = 1; i <= m; i++) {
                cnt1 += result/arr[i];
                cnt2 += (result-1)/arr[i];
            }


            for(int i = 1; i <= m; i++) {
                if(result%arr[i] == 0) cnt2++;
                if(cnt2 == n){
                    ans = i;
                    break;
                }
            }

            System.out.println(ans);
        }


    }
}
