import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long ans = 0;
        long cnt = 1;
        for(int i = 0; i < n; i++){
            if(i == 0) ans += 1;
            else{
                if(arr[i] > arr[i-1]){
                    cnt++;
                    ans += cnt;
                }
                else{
                    cnt = 1;
                    ans += cnt;
                }
            }
        }

        System.out.println(ans);
    }
}