import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	// 이진 검색 트리
	static class Node{
		
		int val;
		Node left;
		Node right;
		
		Node(int val){
			this.val = val;
		}
		
		Node(int val, Node left, Node right){
			this.val = val;
			this.left = left;
			this.right = right;
		}
		
		void insert(int n) {
			
			if(n < this.val) {
				if(this.left == null) {
					this.left = new Node(n);
				}
				else this.left.insert(n);
				
			}
			else {
				if(this.right == null) {
					this.right = new Node(n);
				}
				else this.right.insert(n);
				
			}
			
		}
		
	}
	
	static StringBuilder sb = new StringBuilder();
	
	public static void solve(Node cur) {
		if(cur == null) return;
		solve(cur.left);
		solve(cur.right);
		sb.append(cur.val).append('\n');
	}
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Node tree = new Node(Integer.parseInt(br.readLine())); // 제일 처음 선언할 때 초기화 해줘야 함.
		StringTokenizer st;
		
		while(true) {
			String sam = br.readLine();
			if(sam == null || sam.equals("")) break;
			int idx = Integer.parseInt(sam);
			tree.insert(idx);
		}
		
		solve(tree);
		
		
		System.out.print(sb);
		
	}

}
