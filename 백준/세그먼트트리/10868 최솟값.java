import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	static class MinTree{
		long[] tree;
		int treeSize;
		
		public MinTree(int arrSize){
			int h = (int)Math.ceil(Math.log(arrSize)/Math.log(2));
			this.treeSize = (int)Math.pow(2, h+1);
			tree = new long[treeSize];
		}
		
		public long init(long[] arr, int node, int start, int end) {
			if(start == end) {
				return tree[node] = arr[start];
			}
			
			int mid = (start+end)/2;
			return tree[node] = Math.min(init(arr,node*2,start,mid),
					init(arr,node*2+1,mid+1,end));
		}
		
		public long sum(int node, int start, int end, int left, int right) {
			if(left > end || right < start) return Long.MAX_VALUE;
			
			if(left <= start && end <= right) {
				return tree[node];
			}
			
			int mid = (start+end)/2;
			return Math.min(sum(node*2,start,mid,left,right),
					sum(node*2+1,mid+1,end,left,right));
		}
		
	}
	
	

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		long[] arr = new long[n+1];
		MinTree tree = new MinTree(n);
		
		for(int i = 1; i <= n; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		
		tree.init(arr, 1, 1, n);
		
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			sb.append(tree.sum(1, 1, n, a, b)).append('\n');
		}
		
		System.out.print(sb);
		
	}

}
