import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = 3;
		
		long[] arr1 = new long[n+1];
		long[] arr2 = new long[n+1];
		
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr1[i] = Integer.parseInt(st.nextToken());
			arr2[i] = Integer.parseInt(st.nextToken());
		}
		
		arr1[n] = arr1[0];
		arr2[n] = arr2[0];
		
		long sum1 = 0;
		long sum2 = 0;
		
		for(int i = 0; i < n; i++) {
			sum1 += arr1[i] * arr2[i+1];
			sum2 += arr2[i] * arr1[i+1];
		}
		
		if(sum1 - sum2 > 0) {
			System.out.println(1);
		}
		else if(sum1 - sum2 == 0) {
			System.out.println(0);
		}
		else {
			System.out.println(-1);
		}
	}

}
