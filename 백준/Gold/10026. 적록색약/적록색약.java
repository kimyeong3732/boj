import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

class Main {

	static int n;
	static char[][] map;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		
		map = new char[n][];
		
		for(int i=0; i<n; i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		sb.append(normal()).append(" ").append(abnormal()).append("\n");
		System.out.println(sb);
	}

	static int normal() {
		int count = 0;
		boolean[][] visit = new boolean[n][n];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(visit[i][j])
					continue;
				
				count++;
				
				Queue<Node> q = new ArrayDeque<>();
				q.offer(new Node(j, i));
				char find = map[i][j];
				visit[i][j] = true;
				
				while(!q.isEmpty()) {
					Node node = q.poll();
					
					for(int k=0; k<4; k++) {
						int nx = node.x + dx[k];
						int ny = node.y + dy[k];
						
						if(nx<0 || nx>=n || ny<0 || ny>=n || visit[ny][nx] || map[ny][nx]!=find)
							continue;
						
						visit[ny][nx] = true;
						q.offer(new Node(nx, ny));
					}
				}
			}
		}
		
		return count;
	}
	
	static int abnormal() {
		int count = 0;
		boolean[][] visit = new boolean[n][n];
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(map[i][j] == 'G')
					map[i][j] = 'R';
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(visit[i][j])
					continue;
				
				count++;
				
				Queue<Node> q = new ArrayDeque<>();
				q.offer(new Node(j, i));
				char find = map[i][j];
				visit[i][j] = true;
				
				while(!q.isEmpty()) {
					Node node = q.poll();
					
					for(int k=0; k<4; k++) {
						int nx = node.x + dx[k];
						int ny = node.y + dy[k];
						
						if(nx<0 || nx>=n || ny<0 || ny>=n || visit[ny][nx] || map[ny][nx]!=find)
							continue;
						
						visit[ny][nx] = true;
						q.offer(new Node(nx, ny));
					}
				}
			}
		}
		
		return count;
	}
	
	static class Node {
		int x, y;
		Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
