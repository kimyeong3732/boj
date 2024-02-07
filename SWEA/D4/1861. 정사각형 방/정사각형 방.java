import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			int n = Integer.parseInt(br.readLine());
			int[][] map = new int[n][n];
			
			for(int i=0; i<n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int room = 0;
			int max = 0;
			int[] dx = {-1, 1, 0, 0};
			int[] dy = {0, 0, -1, 1};
			
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					Queue<Node> q = new ArrayDeque<>();
					int count = 0;
					q.offer(new Node(j, i));
					
					while(!q.isEmpty()) {
						Node node = q.poll();
						int cur = map[node.y][node.x];
						count++;
						
						for(int k=0; k<4; k++) {
							int nx = node.x + dx[k];
							int ny = node.y + dy[k];
							
							if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]-cur!=1)
								continue;
							
							q.offer(new Node(nx, ny));
						}
					}
					
					if(max < count) {
						max = count;
						room = map[i][j];
					}
					else if(max==count && room > map[i][j])
						room = map[i][j];
				}
			}
			
			sb.append("#").append(t).append(" ").append(room).append(" ").append(max).append("\n");
		}
		
		System.out.println(sb);
	}

	static class Node {
		public int x;
		public int y;
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
