import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static class Bridge{
        int y;
        int z;
        Bridge(int y, int z){
            this.y = y;
            this.z = z;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 섬 개수
        int m = Integer.parseInt(st.nextToken()); // 다리 수
        ArrayList<Bridge>[] graph = new ArrayList[n+1];
        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>();
        }

        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Bridge(b,c));
            graph[b].add(new Bridge(a,c));

            if(c < left) left = c;
            if(right < c) right = c;

        }

        st = new StringTokenizer(br.readLine());
        int sx = Integer.parseInt(st.nextToken());
        int ex = Integer.parseInt(st.nextToken());

        int ans = -1;

        while(left <= right){
            int mid = (left+right)/2;
            Queue<Integer> q = new ArrayDeque<>();
            boolean[] vis = new boolean[n+1];
            q.offer(sx);
            vis[sx] = true;
            boolean judge = false;

            while(!q.isEmpty()){
                int cur = q.peek();
                if(cur == ex){
                    judge = true;
                    break;
                }
                q.poll();
                for(Bridge nx : graph[cur]){
                    if(mid > nx.z) continue;
                    if(vis[nx.y]) continue;
                    q.offer(nx.y);
                    vis[nx.y] = true;
                }
            }

            if(judge){
                ans = Math.max(ans,mid);
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        System.out.println(ans);

    }
}