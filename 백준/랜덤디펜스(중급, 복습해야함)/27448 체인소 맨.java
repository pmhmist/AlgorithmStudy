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
        int f = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        int[][][] line = new int[n][m][4];
        int ans = 0;

        for(int i = 0 ; i < n; i++){
            String sam = br.readLine();
            for(int j = 0; j < m; j++){
                board[i][j] = sam.charAt(j);
            }
        }

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '#'){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(nx < 0 || nx  >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == '#'){
                            line[i][j][dir] = 100; // 가르먄 안되는 곳
                        }
                        else{
                            line[i][j][dir] = 1; // 갈라야 하는 곳
                        }
                    }

                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int dir = 0; dir < 4; dir++){
                    if(line[i][j][dir] == 1){
                        Queue<Pair> q = new ArrayDeque<>();
                        boolean outside = false;
                        int tmpdir = dir;
                        tmpdir = (dir+1)%4;
                        q.offer(new Pair(i,j));
                        int tx = i;
                        int ty = j;
                        while(true){
                         int nx = tx + dx[tmpdir];
                         int ny = ty + dy[tmpdir];
                         if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                             outside = true;
                             break;
                         }
                         if(line[nx][ny][dir] == 100) break;
                         q.offer(new Pair(nx,ny));
                         tx = nx;
                         ty = ny;
                        }
                        tmpdir = (tmpdir + 2)%4;
                        tx = i;
                        ty = j;
                        while(true){
                            int nx = tx + dx[tmpdir];
                            int ny = ty + dy[tmpdir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                                outside = true;
                                break;
                            }
                            if(line[nx][ny][dir] == 100) break;
                            q.offer(new Pair(nx,ny));
                            tx = nx;
                            ty = ny;
                        }
                        int tmp = 0;
                        while(!q.isEmpty()){
                            int x = q.peek().x;
                            int y = q.peek().y;
                            if(line[x][y][dir] == 1){
                                tmp++;
                                line[x][y][dir] = 2;
                            }
                            else{
                                int nx = x + dx[dir];
                                int ny = y + dy[dir];
                                if(nx < 0 || nx >= n || ny < 0 || ny >= m ){

                                }
                                else{
                                    if(line[nx][ny][(dir+2)%4] == 1){
                                        tmp++;
                                        line[nx][ny][(dir+2)%4] = 2;
                                    }
                                }
                            }
                            q.poll();
                        }
                        if(outside){
                            ans += Math.min(f,tmp);
                        }
                        else{
                            ans += tmp;
                        }
                    }
                }
            }
        }

        System.out.println(ans);

    }
}