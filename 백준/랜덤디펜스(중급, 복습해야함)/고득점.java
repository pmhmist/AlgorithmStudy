import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int turn = 0; turn < T; turn++) {
			String base = br.readLine();
			
			int ans = 0;
			int mv = base.length() - 1;
			for(int i = 0; i < base.length(); i++) {
				int nxt = base.charAt(i) - 'A';
				int ck1 = nxt;
				int ck2 = 26-nxt;
				ans += Math.min(ck1, ck2);
			}
			
			for(int i = 0; i < base.length(); i++) {
				int idx = i+1;
				while(idx < base.length() && base.charAt(idx) == 'A') {
					idx++;
				} 
				
				mv = Math.min(mv, 2*i + (base.length() - idx));
				mv = Math.min(mv, i + 2*(base.length() - idx));
			}
			
			
			ans += mv;
			
			System.out.println(ans);
		}
		
		
	}

}
