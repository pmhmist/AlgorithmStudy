import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] parent;

    public static class Pair implements Comparable<Pair>{
        int x;
        int y;
        int cost;

        Pair(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair p) {
            return this.cost - p.cost;
        }
    }

    public static int find(int x) {
        if(x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }

    public static boolean union(int x, int y){
        int a = find(x);
        int b = find(y);

        if(a == b) return false;
        else{
            parent[b] = a;
            return true;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        while(true) {
            st = new StringTokenizer(br.readLine());

            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int sum = 0;
            int ans = 0;

            if(m == 0 && n == 0) break;

            PriorityQueue<Pair> pq = new PriorityQueue<>();
            parent = new int[m];
            for (int i = 0; i < m; i++) {
                parent[i] = i;
            }

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());
                pq.offer(new Pair(x,y,z));
                sum += z;
            }

            while(!pq.isEmpty()) {
                Pair cur = pq.peek();
                pq.poll();
                if(union(cur.x,cur.y)){
                    ans += cur.cost;
                }
            }

            sb.append(sum - ans).append('\n');
        }

        System.out.println(sb);
    }
}
