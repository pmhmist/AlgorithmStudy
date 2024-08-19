import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static long solve(long x1, long x2, long x3, long y1, long y2, long y3) {
		long tmp = (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
		if(tmp > 0) return 1;
		else if(tmp == 0) return 0;
		else return -1;
	}
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long x1,x2,x3,x4;
		long y1,y2,y3,y4;
		
		x1 = Long.parseLong(st.nextToken());
		y1 = Long.parseLong(st.nextToken());
		x2 = Long.parseLong(st.nextToken());
		y2 = Long.parseLong(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		
		x3 = Long.parseLong(st.nextToken());
		y3 = Long.parseLong(st.nextToken());
		x4 = Long.parseLong(st.nextToken());
		y4 = Long.parseLong(st.nextToken());
		
		long ck1 = solve(x1,x2,x3,y1,y2,y3)*solve(x1,x2,x4,y1,y2,y4);
		long ck2 = solve(x3,x4,x1,y3,y4,y1)*solve(x3,x4,x2,y3,y4,y2);
		
		if(ck1 < 0 && ck2 < 0) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}
		
	}

}
