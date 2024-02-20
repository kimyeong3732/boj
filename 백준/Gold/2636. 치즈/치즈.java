import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int n, m;
	static int time = 0, lastcnt;
	static Queue<Point> q = new ArrayDeque<>();
	static int[][] map;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		run();
		
		System.out.println(time);
		System.out.println(lastcnt);
	}

	
	static void run() {
		q.offer(new Point(0, 0));
		
		while(!q.isEmpty()) {
			fill();
			
			int cnt = 0;
			
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					if(map[i][j] == 1) {
						for(int k=0; k<4; k++) {
							int nx = j + dx[k];
							int ny = i + dy[k];
							
							if(nx<0 || nx>=m || ny<0 || ny>=n || map[ny][nx]>=0)
								continue;
							
							map[i][j] = 0;
							cnt++;
							q.offer(new Point(j, i));
							break;
						}
					}
				}
			}
			
			if(cnt > 0) {
				time++;
				lastcnt = cnt;
			}
		}
	}
	
	static void fill() {
		while(!q.isEmpty()) {
			Point p = q.poll();
			map[p.y][p.x] = -1;
			
			for(int i=0; i<4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				
				if(nx<0 || nx>=m || ny<0 || ny>=n || map[ny][nx]!=0)
					continue;
				
				map[ny][nx] = -1;
				q.offer(new Point(nx, ny));
			}
		}
	}
}
