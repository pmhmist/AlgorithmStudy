import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		char[][] board = new char[n][n];
		
		for(int i = 0; i < n; i++) {
			String tmp = br.readLine();
			for(int j = 0; j < n; j++) {
				board[i][j] = tmp.charAt(j);
			}
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int tmp = 0;
			boolean[] vis = new boolean[n];
			for(int j = 0; j < n; j++) {
				if(i == j) continue;
				if(board[i][j] == 'Y') {
					tmp++;
					for(int z = 0; z < n; z++) {
						if(board[j][z] == 'Y' && board[i][z] == 'N') {
							if(i == z) continue;
							if(vis[z]) continue;
							else {
								vis[z] = true;
								tmp++;
							}
						}
					}
				}
			}
			ans = Math.max(ans, tmp);
		}
		
		System.out.println(ans);
		
	}

}
