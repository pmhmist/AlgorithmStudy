import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    int cnt = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int k = Integer.parseInt(st.nextToken());

        int len = 1;

        while(true) {
            int tmp = (int)Math.pow(2,len);
            if(k > tmp) {
                len++;
                k -= tmp;
            }
            else break;
        }
        k--;
        StringBuilder ans = new StringBuilder();

        for(int i = 0; i < len; i++) {
            if(k == 0) {
                ans.insert(0,4);
            }
            else {
                if(k%2 == 0) {
                    ans.insert(0,4);
                }
                else {
                    ans.insert(0,7);
                }
                k /= 2;
            }
        }

        System.out.println(ans);

    }
}
