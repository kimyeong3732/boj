import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int n, m, k;
	static int[][] map;
	static boolean[][][] visit;
	static int[] dx = {-1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1};
	static int[] dy = {0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		k = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visit = new boolean[n][m][k+1];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		bfs();
	}
	
	static void bfs() {
		Queue<Node> q = new ArrayDeque<>();
		
		q.offer(new Node(0, 0, 0, k));
		visit[0][0][k] = true;
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			
			if(node.x==m-1 && node.y==n-1) {
				System.out.println(node.time);
				return;
			}
			
			for(int i=0; i<12; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				
				if(nx<0 || nx>=m || ny<0 || ny>=n || map[ny][nx]==1 || visit[ny][nx][node.count])
					continue;
				
				if(node.count==0 && i>=4)
					break;
				
				if(i>=4 && visit[ny][nx][node.count-1])
					continue;
				
				if(i < 4) {
					visit[ny][nx][node.count] = true;
					q.offer(new Node(nx, ny, node.time+1, node.count));
				}
				if(i >= 4) {
					visit[ny][nx][node.count-1] = true;
					q.offer(new Node(nx, ny, node.time+1, node.count-1));
				}
			}
		}
		
		System.out.println(-1);
	}

	static class Node {
		int x, y;
		int time, count;
		public Node(int x, int y, int time, int count) {
			this.x = x;
			this.y = y;
			this.time = time;
			this.count = count;
		}
	}
}
