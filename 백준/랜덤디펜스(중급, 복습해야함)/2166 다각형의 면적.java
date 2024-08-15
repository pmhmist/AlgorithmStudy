import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int[] arr1 = new int[n+1];
		int[] arr2 = new int[n+1];
		
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
		
		double total = Math.abs(sum1-sum2)/2.0;
		String ans = String.format("%.1f", total);
		System.out.println(ans);
	}

}
