import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static int[][] boardA;
    static int[][] boardB;
    static boolean[][] vis;
    static boolean[][][] cycle; // 무한루프 여부 파악

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        boardA = new int[h][w];
        boardB = new int[h][w];
        vis = new boolean[h][w]; // 높이, 너비, 방향, A,B 구분

        st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        for(int i = 0; i < h; i++){
            String sam = br.readLine();
            for(int j = 0; j < w; j++){
                boardA[i][j] = sam.charAt(j) - '0';
            }
        }

        for(int i = 0; i < h; i++){
            String sam = br.readLine();
            for(int j = 0; j < w; j++){
                boardB[i][j] = sam.charAt(j) - '0';
            }
        }

        int ans = 0;
        int tmp = 0;
        int x = r;
        int y = c;
        while(true){ // 먼지제거 시작
            if(tmp > 100000) break;
            boolean stop = false;
            if(!vis[x][y]){ // boardA
                vis[x][y] = true;

                d = (d + boardA[x][y])%4;
                x = x + dx[d];
                y = y + dy[d];

                tmp++;
                ans += tmp;
                tmp = 0;

                if(x < 0 || x >= h || y < 0 || y >= w){
                    stop = true;
                }
                if(stop) break;


            }
            else{ // boardB
                d = (d + boardB[x][y])%4;
                x = x + dx[d];
                y = y + dy[d];

                tmp++;

                if(x < 0 || x >= h || y < 0 || y >= w){
                    stop = true;
                }
                if(stop) break;


            }
        }

        System.out.println(ans);

    }
}