import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		long n = Long.parseLong(st.nextToken());
		long m = Long.parseLong(st.nextToken());
		
		long[] arr = new long[(int)n];
		
		for(int i = 0; i < n; i++) {
			long tmp = Long.parseLong(br.readLine());
			arr[i] = tmp;
		}
		
		long left = 1;
		long right = 1000000000000000005L;
		long ans = Long.MAX_VALUE - 10;
		while(left <= right) {
			long mid = (left + right)/2;
			long tmp = 0;
			for(int i = 0; i < n; i++) {
				tmp += mid/arr[i];
				if(tmp >= m) break;
			}
			
			if(tmp >= m) {
				ans = Math.min(ans, mid);
				right = mid-1;
			}
			else {
				left = mid + 1;
			}
		}
		
		System.out.println(ans);
	}

}
