import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] dx ={1,-1,-1,-1};
    static int[] dy = {1,1,-1,1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());


        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int time = Integer.parseInt(st.nextToken());

        int nx = (time)%(2*w);
        int ny = (time)%(2*h);
        boolean go = true;
        for(int i = 0; i < nx; i++){
            if(go){
                if(x == w){
                    go = false;
                    x--;
                }
                else{
                    x++;
                }
            }
            else{
                if(x == 0){
                    go = true;
                    x++;
                }
                else{
                    x--;
                }
            }
        }

        go = true;
        for(int i = 0; i < ny; i++){
            if(go){
                if(y == h){
                    go = false;
                    y--;
                }
                else{
                    y++;
                }
            }
            else{
                if(y == 0){
                    go = true;
                    y++;
                }
                else{
                    y--;
                }
            }
        }

        System.out.println(x + " " + y);
    }
}