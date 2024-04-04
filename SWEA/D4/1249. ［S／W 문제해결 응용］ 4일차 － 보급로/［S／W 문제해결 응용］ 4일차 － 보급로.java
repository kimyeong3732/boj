import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class Solution {

	static int N;
	static int[][] map;
	static boolean[][] visit;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			
			map = new int[N][N];
			visit = new boolean[N][N];
			
			for(int i=0; i<N; i++) {
				char[] strArray = br.readLine().toCharArray();
				
				for(int j=0; j<N; j++) {
					map[i][j] = strArray[j] - '0';
				}
			}
			
			sb.append("#").append(t).append(" ").append(dijkstra()).append("\n");
		}
		
		System.out.println(sb);
	}
	
	static int dijkstra() {
		PriorityQueue<myPoint> pq = new PriorityQueue<>((e1, e2) ->
				e1.cost==e2.cost ? (e1.x+e1.y)-(e2.x+e2.y) : e1.cost-e2.cost);
		
		pq.offer(new myPoint(0, 0, 0));
		
		while(!pq.isEmpty()) {
			myPoint node = pq.poll();
			
			if(visit[node.y][node.x])
				continue;
			
			if(node.x==N-1 && node.y==N-1)
				return node.cost;
			
			visit[node.y][node.x] = true;
			
			for(int i=0; i<4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				
				if(nx<0 || nx>=N || ny<0 || ny>=N || visit[ny][nx])
					continue;
				
				pq.offer(new myPoint(nx, ny, node.cost+map[ny][nx]));
			}
		}
		
		return 0;
	}

	static class myPoint {
		int x, y, cost;
		myPoint(int x, int y, int cost) {
			this.x = x;
			this.y = y;
			this.cost = cost;
		}
	}
}
