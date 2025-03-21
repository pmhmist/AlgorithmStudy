import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n = 0;
    static int ans = 0;

    public static void solve(int[] base, int val) {
        if(base.length == 2) {
            if(ans < val) ans = val;
            return;
        }

        int len = base.length;
        for(int i = 1; i < len-1; i++) {
            int[] nxt = new int[len-1];
            int score = base[i-1] * base[i+1];

            int idx = 0;
            for(int j = 0; j < len; j++) {
                if(i == j) continue;
                nxt[idx] = base[j];
                idx++;
            }

            solve(nxt,val + score);
        }

    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        solve (arr,0);

        System.out.println(ans);

    }
}
