import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static long solve(long x1, long x2, long x3, long y1, long y2, long y3) {
		long result =  x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;
		if(result > 0) return 1;
		else if(result < 0) return -1;
		else return 0;
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
		
		boolean cmp1 = false;
		boolean cmp2 = false;
		boolean cmp3 = false;
		boolean cmp4 = false;
		
		if(Math.min(x1,x2) <= Math.max(x3, x4)) cmp1 = true;
		if(Math.min(x3, x4) <= Math.max(x1, x2)) cmp2 = true;
		if(Math.min(y1,y2) <= Math.max(y3, y4)) cmp3 = true;
		if(Math.min(y3, y4) <= Math.max(y1, y2)) cmp4 = true;
		
		if(ck1 == 0 && ck2 == 0) {
			if(cmp1 && cmp2 && cmp3 && cmp4) {
				System.out.println(1);
			}
			else System.out.println(0);
		}
		else if(ck1 <= 0 && ck2 <= 0) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}
		
	}

}