import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[30005];
        int sz = 0;
        for(int i = 1; i <= n; i++){

            Queue<Integer> q = new ArrayDeque<>();
            q.offer(n);
            q.offer(i);

            int a1 = n;
            int a2 = i;
            int cnt = 2;

            while(a1 - a2 >= 0){
                q.offer(a1 - a2);
                int tmp = a1 - a2;
                a1 = a2;
                a2 = tmp;
                cnt++;
            }

            if(sz < cnt){
                sz = cnt;
                for(int j = 0; j < sz; j++){
                    arr[j] = q.peek();
                    q.poll();
                }

            }

        }

        System.out.println(sz);
        for(int i = 0; i < sz; i++){
            System.out.print(arr[i] + " ");
        }

    }
}