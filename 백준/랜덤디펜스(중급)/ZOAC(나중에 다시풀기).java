import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static String base;
    static boolean[] vis;
    public static void solve(int start, int end){
        String tmp = "";
        char tmp2 = base.charAt(start);
        int ck = start;

        for(int i = start; i <= end; i++){
            if(tmp2 > base.charAt(i)){
                tmp2 = base.charAt(i);
                ck = i;
            }
        }

        vis[ck] = true;

        for(int i = 0; i < base.length(); i++){
            if(vis[i]) tmp += base.charAt(i);
        }
        System.out.println(tmp);

        if(ck+1 <= end) solve(ck+1,end);
        if(start <= ck-1) solve(start,ck-1);

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        base = br.readLine();
        vis = new boolean[base.length()];
        solve(0,base.length()-1);

    }
}