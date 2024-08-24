import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    public static class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] board = new int[n][m];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;
        boolean[][] vis;
        Stack<Pair> s = new Stack<>();

        while(true){
            boolean judge = false;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == 1) judge = true;
                }
            }

            if(!judge) break;

            vis = new boolean[n][m];
            s.clear();
            int[][] board2 = new int[n][m];

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == 0 && !vis[i][j]){
                        Queue<Pair> q = new ArrayDeque<>();
                        q.offer(new Pair(i,j));
                        vis[i][j] = true;
                        boolean melt = false;

                        while(!q.isEmpty()){
                            int x = q.peek().x;
                            int y = q.peek().y;
                            s.push(new Pair(x,y));
                            q.poll();

                            for(int dir = 0; dir < 4; dir++){
                                int nx = x + dx[dir];
                                int ny = y + dy[dir];

                                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                                    melt = true;
                                    continue;
                                }
                                if(vis[nx][ny]) continue;
                                if(board[nx][ny] == 1) continue;
                                vis[nx][ny] = true;
                                q.offer(new Pair(nx,ny));
                            }
                        }

                        while(!s.isEmpty()){
                            int x = s.peek().x;
                            int y = s.peek().y;
                            s.pop();
                            if(melt) board2[x][y] = 1;
                        }

                    }
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == 1){
                        int cnt = 0;
                        for(int dir = 0; dir < 4; dir++){
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];

                            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                                cnt++;
                                continue;
                            }
                            if(board2[nx][ny] == 1){
                                cnt++;
                            }
                        }
                        if(cnt >= 2){
                            board[i][j] = 0;
                        }
                    }
                }
            }

            ans++;
        }
        System.out.println(ans);
    }
}