import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        for(int turn = 0; turn < T; turn++){
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int ans = 0;
            if(k == 1) ans = 1;
            else {
                int tmp1= 0;
                int tmp2 = 0;
                for (int i = 0; i < k; i++) {
                    if (i  >= n) break;
                    tmp1++;
                }

                tmp2 = tmp1;

                for (int i = 1; i < k; i++) {
                    if (i  >= m) break;
                    tmp2 += tmp1;
                }
                ans = tmp2;
            }
            sb.append(ans).append('\n');
        }
        System.out.println(sb);
    }

}
