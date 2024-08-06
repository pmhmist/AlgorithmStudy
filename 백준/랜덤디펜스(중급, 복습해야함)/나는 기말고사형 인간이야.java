import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static class Pair implements Comparable<Pair>{
		int x;
		int y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			return o.y - this.y;
		}
		
	}
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int time = 24 * n;
		int[] a = new int[m];
		int[] b = new int[m];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) {
			b[i] = Integer.parseInt(st.nextToken());
			int ck = a[i] + b[i];
			if(ck > 100) b[i] = 100 - a[i];
		}
		
		int ans = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		
		for(int i = 0; i < m; i++) {
			pq.offer(new Pair(a[i],b[i]));
		}
		
		while(time-- > 0) {
			if(pq.isEmpty()) break;
			int x = pq.peek().x;
			int y = pq.peek().y;
			pq.poll();
			x = x + y;
			if(x >= 100) {
				ans+= 100;
			}
			else {	
				int tmp = x + y;
				if(x+y > 100) y = 100 - x;
				pq.offer(new Pair(x,y));
			}
		}
		
		while(!pq.isEmpty()) {
			int x = pq.peek().x;
			pq.poll();
			ans += x;
		}
		
		System.out.println(ans);
	}

}
