import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	static long mod = 1_000_000_007;
	
	public static class MulTree{
        long tree[];
        int treeSize;

        public MulTree(int arrSize){
            int h = (int) Math.ceil(Math.log(arrSize)/ Math.log(2));

            this.treeSize = (int) Math.pow(2,h+1);
            tree = new long[treeSize];
        }

        public long init(long[] arr, int node, int start,int end){
            
            if(start == end){
                return tree[node] = arr[start];
            }

            return tree[node] = init(arr,node*2,start,(start+ end)/2)*
                    init(arr,node*2+1,(start+end)/2+1,end) % mod;
        }

        public void update(int node, int start, int end, int idx, long diff){
            if(idx < start || end < idx) return;

            if (start == end) {
                tree[node] = diff;
                return;
            }
            
            update(node*2, start, (start+end)/2, idx, diff);
            update(node*2+1, (start+end)/2+1, end, idx, diff);
            
            tree[node] = tree[node * 2]*tree[node * 2 + 1] % mod;
        }

        public long sum(int node, int start, int end, int left, int right){
            if(left > end || right < start){
                return 1;
            }

            if(left <= start && end <= right){
                return tree[node];
            }

            return sum(node*2, start, (start+end)/2, left, right)*
                    sum(node*2+1, (start+end)/2+1, end, left, right) % mod;
        }
    }
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long[] arr;
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		arr = new long[n+1];
		for(int i = 1; i <= n; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		
		MulTree tree = new MulTree(n);
		tree.init(arr, 1, 1, n);
		
		for(int turn = 0; turn < m + k; turn++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			if(a == 1) {
				arr[b] = c;
				tree.update(1, 1, n, b, c);
				
			}
			else {
				System.out.println(tree.sum(1, 1, n, b, c));
			}
			
		}
	}

}
