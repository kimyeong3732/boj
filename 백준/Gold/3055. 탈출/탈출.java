import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N, M;
	static char[][] map;
	static boolean[][] visit;
	static Queue<point> q = new ArrayDeque<>();
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new char[N][M];
		visit = new boolean[N][M];
		
		int hx = -1;
		int hy = -1;
		for(int i=0; i<N; i++) {
			String str = br.readLine();
			
			for(int j=0; j<M; j++) {
				char c = str.charAt(j);
				map[i][j] = c;
				
				if(c == 'S') {
					hx = j;
					hy = i;
				}
				else if(c == '*') {
					q.offer(new point(j, i, 0, true));
					visit[i][j] = true;
				}
			}
		}
		
		q.offer(new point(hx, hy, 0, false));
		visit[hy][hx] = true;

		bfs();
	}
	
	static void bfs() {
		while(!q.isEmpty()) {
			point p = q.poll();
			
			if(!p.isWater && map[p.y][p.x]=='D') {
				System.out.println(p.cnt);
				return;
			}
			
			for(int i=0; i<4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				
				if(nx<0 || nx>=M || ny<0 || ny>=N || visit[ny][nx] || map[ny][nx]=='X')
					continue;
				
				if(p.isWater && map[ny][nx]=='D')
					continue;
				
				visit[ny][nx] = true;
				q.offer(new point(nx, ny, p.cnt+1, p.isWater));
			}
		}
		
		System.out.println("KAKTUS");
	}

	static class point {
		int x, y, cnt;
		boolean isWater;
		public point(int x, int y, int cnt, boolean isWater) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.isWater = isWater;
		}
	}
}
