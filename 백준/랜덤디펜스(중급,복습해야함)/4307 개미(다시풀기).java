import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        for (int turn = 0; turn < T; turn++) {
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            boolean[] arr = new boolean[len + 1];
            for(int i = 0 ; i< n; i++){
                st= new StringTokenizer(br.readLine());
                int tmp = Integer.parseInt(st.nextToken());
                arr[tmp] = true;
            }

            int left = len/2;
            int right = len/2;

            int ans1 = 0;
            int ans2 = 0;

            while(left > 0){
                if(arr[left]) break;
                left--;
            }
            while(right < len){
                if(arr[right]) break;
                right++;
            }
            ans1 = Math.max(left,len-right);

            left = 0;
            right = len;

            while(left < len){
                if(arr[left]) break;
                left++;
            }

            while(right > 0){
                if(arr[right]) break;
                right--;
            }
            ans2 = Math.max(len-left,right);

            sb.append(ans1 + " " + ans2).append('\n');
        }
        System.out.println(sb);
    }
}