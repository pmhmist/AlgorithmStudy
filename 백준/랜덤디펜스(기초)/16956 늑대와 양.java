import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];

        for(int i = 0; i < n; i++){
            String sam = br.readLine();
            for(int j = 0; j < m; j++){
                board[i][j] = sam.charAt(j);
                if(board[i][j] =='.') board[i][j] = 'D';
            }
        }
        boolean judge = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'S'){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 'W') judge = false;
                    }
                }
            }
        }
        if(judge){
            System.out.println(1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    System.out.print(board[i][j]);
                }
                System.out.println();
            }
        }
        else{
            System.out.println(0);
        }

    }
}