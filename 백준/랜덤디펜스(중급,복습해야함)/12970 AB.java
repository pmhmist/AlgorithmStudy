import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder("-1");

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        for(int bnum = 0; bnum <= n; bnum++) {
            int anum = n - bnum;
            int cnt = 0;
            int[] sv = new int[n+1];

            for(int i = 0; i < anum; i++) {
                if(cnt == k){
                    sv[0]++;
                }
                else {
                    if(cnt + bnum > k) {
                        sv[k-cnt]++;
                        cnt = k;
                    }
                    else{
                        sv[bnum]++;
                        cnt += bnum;
                    }
                }
            }

            if(cnt == k) {
                sb = new StringBuilder("");
                for(int i = 0; i <= bnum; i++){
                    while(sv[i] != 0){
                        sb.insert(0,"A");
                        sv[i]--;
                    }

                    if(sb.length() == n) break;
                    sb.insert(0,'B');
                }

                break;
            }
        }



        System.out.println(sb);
    }
}
