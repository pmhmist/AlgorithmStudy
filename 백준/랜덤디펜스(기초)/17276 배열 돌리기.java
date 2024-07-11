import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        for(int turn = 0; turn < T; turn++){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            int[][] board = new int[n][n];
            int[][] board2 = new int[n][n];
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int depth = n/2;
            if(d < 0) d += 360;

            d = d / 45;

            for(int rotate = 0; rotate < d; rotate++){

                // 1.
                int x = 0;
                int y = 0;
                while(x < n){
                    board2[x][n/2] = board[x][y];
                    x++;
                    y++;
                }

                //2.
                x = 0;
                y = n/2;
                int x2 = 0;
                int y2 = n-1;
                while(x<n){
                    board2[x2][y2] = board[x][y];
                    x++;
                    x2++;
                    y2--;
                }

                //3.
                x = 0;
                y = n-1;
                x2 = n/2;
                y2 = n-1;
                while(x < n){
                    board2[x2][y2] = board[x][y];
                    x++;
                    y--;
                    y2--;
                }

                //4.
                x = n/2;
                y = 0;
                x2 = 0;
                y2 = 0;
                while(y < n){
                    board[x2][y2] = board[x][y];
                    x2++;
                    y2++;
                    y++;
                }

                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(board2[i][j] != 0){
                            board[i][j] = board2[i][j];
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }

        }

    }
}