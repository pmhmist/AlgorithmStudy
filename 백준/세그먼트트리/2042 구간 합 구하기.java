import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {

	public static class SegmentTree {
		long []tree;
		int treeSize;

		public SegmentTree(int arrSize) {
			int h = (int) Math.ceil(Math.log(arrSize) / Math.log(2));
			this.treeSize = (int) Math.pow(2, h + 1);
			tree = new long[treeSize];
		}

		public long init(long[] arr, int node, int start, int end) {

			// 배열의 시작과 끝이 같다면 leaf노드, 원소 배열값 그대로 담기
			if (start == end) {
				return tree[node] = arr[start];
			}

			// leaf 노드가 아니면, 자식노드 합 담기
			return tree[node] = init(arr, node * 2, start, (start + end) / 2)
					+ init(arr, node * 2 + 1, (start + end) / 2 + 1, end);
		}
		
		// idx : 변경된 데이터의 idx, node : 현재노드
		public void update(int node, int start, int end, int idx, long diff) {
			if(idx < start || end < idx) return;
			
			tree[node] += diff;
			
			// 리프노드 아니라면 업데이트 필요
			if(start != end) {
				update(node*2, start, (start+end)/2, idx, diff);
				update(node*2+1, (start+end)/2+1, end, idx, diff);
			}
		}
		
		public long sum(int node, int start, int end, int left, int right) {
			if(left > end || right < start) {
				return 0;
			}
			
			if(left <= start && end <= right) {
				return tree[node];
			}
			
			return sum(node*2,start,(start+end)/2,left,right)+
					sum(node*2+1,(start+end)/2+1,end,left,right);
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken()); // 수의 갯수
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		long[] arr = new long[n+1];
		for(int i = 1; i <= n; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		
		SegmentTree segtree = new SegmentTree(n);
		segtree.init(arr, 1, 1, n);
		
		for(int i = 0; i < m + k; i++) {
			st = new StringTokenizer(br.readLine());
			int ck = Integer.parseInt(st.nextToken());
			if(ck == 1) {
				int b = Integer.parseInt(st.nextToken());
				long c = Long.parseLong(st.nextToken());
				segtree.update(1, 1, n, b, c-arr[b]);
				
			}
			else {
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				sb.append(segtree.sum(1,1,n,b,c)).append('\n');
			}
			
		}
		System.out.print(sb);
		
	}

}
