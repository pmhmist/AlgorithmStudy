import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int[][] board = new int[105][105];
        boolean[][] ck = new boolean[105][105];
        for(int turn = 0; turn < 4; turn++){
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            for(int i = y1; i <= y2; i++){
                for(int j = x1; j <= x2; j++){
                    board[i][j] = 1;
                    if(i != y2 && j != x2){
                        ck[i][j] = true;
                    }
                }
            }

        }
        int ans = 0;
        for(int i = 0 ; i < 105; i++){
            for(int j = 0; j < 105; j++){
                if(board[i][j] == 1 && ck[i][j]){
                    if(board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1){
                        ans++;
                    }
                }
            }
        }
        System.out.println(ans);

    }
}