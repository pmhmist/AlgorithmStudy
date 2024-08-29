import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static class Node implements Comparable<Node>{
		int x;
		int cost;
		
		Node(int x, int cost) {
			this.x = x;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o) {
			return this.cost - o.cost;
		}
	}

	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		for(int turn = 0; turn < T; turn++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			
			ArrayList<Node>[] board = new ArrayList[n+1];
			for(int i = 0; i <= n; i++) {
				board[i] = new ArrayList<>();
			}
			
			int[] dist = new int[n+1];
			Arrays.fill(dist, Integer.MAX_VALUE);
			
			for(int i = 0; i < d; i++) {
				st = new StringTokenizer(br.readLine());
				
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int time = Integer.parseInt(st.nextToken());
				
				board[b].add(new Node(a,time));
				
			}
			
			PriorityQueue<Node> pq = new PriorityQueue<>();
			pq.offer(new Node(s,0));
			dist[s] = 0;
			
			while(!pq.isEmpty()) {
				Node cur = pq.peek();
				int curx = cur.x;
				int curcost = cur.cost;
				pq.poll();
				for(Node nxt : board[curx]) {
					if(dist[nxt.x] > curcost + nxt.cost) {
						dist[nxt.x] = curcost + nxt.cost;
						pq.offer(new Node(nxt.x,dist[nxt.x]));
					}
				}
			}
			
			int num = 0;
			int mx = 0;
			for(int i = 1; i <= n; i++) {
				if(dist[i] != Integer.MAX_VALUE) {
					num++;
					if(mx < dist[i]) mx = dist[i];
				}
			}
			
			sb.append(num + " " + mx).append('\n');
			
		}
		
		System.out.print(sb);
				
	}

}
