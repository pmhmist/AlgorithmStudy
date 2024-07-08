import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static String base;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        int[] arr1 = new int[6];
        arr1[0] = 5000000;
        arr1[1] = 3000000;
        arr1[2] = 2000000;
        arr1[3] = 500000;
        arr1[4] = 300000;
        arr1[5] = 100000;


        int[] arr2 = new int[5];
        arr2[0] = 5120000;
        arr2[1] = 2560000;
        arr2[2] = 1280000;
        arr2[3] = 640000;
        arr2[4] = 320000;


        for(int i = 0; i < T; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int score1 = 0;
            int score2 = 0;

            if(a == 1) a = 0;
            else if(2 <= a && a <= 3) a = 1;
            else if(4 <= a && a <= 6) a = 2;
            else if(7 <= a && a <= 10) a = 3;
            else if(11 <= a && a <= 15) a = 4;
            else if(16 <= a && a <= 21) a = 5;
            else a = 6;

            if(a != 6) score1 = arr1[a];

            if(b == 1) b = 0;
            else if(2 <= b && b <= 3) b = 1;
            else if(4 <= b && b <= 7) b = 2;
            else if(8 <= b && b <= 15) b = 3;
            else if(16 <= b && b <= 31) b = 4;
            else b = 5;

            if(b != 5) score2 = arr2[b];

            System.out.println(score1 + score2);

        }

    }
}