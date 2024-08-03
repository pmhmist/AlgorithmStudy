import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	// 블로그글 학습하고 참고해온 트라이 코드
	// 한 문자열당 한 노드씩 차지하고 map으로 관리
	static double ans = 0;
	public static class Node{
		// 노드와 자식 노드들을 저장
		HashMap<Character, Node> child;
		// 이 노드가 단어의 끝인지 저장
		boolean endOfWord;
		
		public Node() {
			this.child = new HashMap<>();
			this.endOfWord = false;
		}
	}
	
	public static class Trie{
		Node root;
		
		public Trie() {
			this.root = new Node();
		}
		
		public void insert(String str) {
			// 시작노드를 루트노드로 설정
			Node node = this.root;
			
			for(int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				node.child.putIfAbsent(c, new Node());
				// 해당 문자열 노드가 없을때만 추가해주기 위해 putIfAbsent 사용
				node = node.child.get(c); // 자식노드 이동
			}
			node.endOfWord = true;
		}
		
		boolean search(String str) {
			Node node = this.root;
			
			for(int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				
				if(node.child.containsKey(c)) {
					if(i == 0) {
						ans++;
					}
					else {
						if(node.child.size() != 1 || node.endOfWord) ans++;
					}
					node = node.child.get(c);
				}
				else {
					return false;
				}
				
			}
	
			return node.endOfWord;// 마지막 노드 도달 시 노드의 endOfWord를 반환
		}
		
		public boolean delete(String str) {
			boolean result = delete(this.root, str, 0);
			return result;
		}
		
		private boolean delete(Node node, String str, int idx) {
			char c = str.charAt(idx);
			
			if(!node.child.containsKey(c)) return false;
			
			Node cur = node.child.get(c);
			idx++;
			if(idx == str.length()) {
				if(!cur.endOfWord) return false;
				
				// false로 바꿔주면 지우려는 문자열 못찾는다.
				cur.endOfWord = false;
				
				if(cur.child.isEmpty()) {
					node.child.remove(c);
				}
			}
			else {
				// 재귀적으로 현재 노드부터 다시 호출
				if(!this.delete(cur,str,idx)) return false;
				
				//true 반환받고 자식노드 비었으면 현재노드 삭제
				if(!cur.endOfWord && cur.child.isEmpty()) {
					node.child.remove(c);
				}
			}	
			return true;
		}
	}
	
	
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		String ck;
		while((ck = br.readLine()) != null) {
			int n = Integer.parseInt(ck);
			String[] arr = new String[n];
			int idx = 0;
			ans = 0;
			Trie t = new Trie();
			for(int i = 0; i < n; i++) {
				String tmp = br.readLine();
				arr[idx] = tmp;
				t.insert(tmp);
				idx++;
			}
			for(int i = 0; i < n; i++) {
				t.search(arr[i]);
			}
			ans = ans/n;
			ans = Math.round(ans*100.0)/100.0;
			System.out.println(String.format("%.2f", ans));
		}
		
	}

}
