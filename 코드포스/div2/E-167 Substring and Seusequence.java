import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());

        for (int turn = 0; turn < T; turn++) {
            String tmp1 = br.readLine();
            String tmp2 = br.readLine();

            int ans = tmp1.length() + tmp2.length();
            for(int i = 0; i < tmp2.length(); i++){
                int tmp = i;
                for(int j = 0; j < tmp1.length(); j++){
                    if(tmp < tmp2.length() && tmp1.charAt(j) == tmp2.charAt(tmp)) {
                        tmp++;
                    }
                }
                ans = Math.min(ans,tmp1.length()+tmp2.length() - (tmp - i));
            }

            sb.append(ans).append('\n');
        }
        System.out.println(sb);
    }
}
