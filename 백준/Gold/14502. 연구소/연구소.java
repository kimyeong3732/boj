import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N, M, max;
	static int[][] map;
	static int[][] copymap;
	static List<Point> virus = new ArrayList<>();
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		max = 0;
		map = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
				if(map[i][j] == 2) {
					virus.add(new Point(j, i));
				}
			}
		}
		
		dfs(0, -1, 0);
		System.out.println(max);
	}
	
	static void dfs(int x, int y, int cnt) {
		if(cnt == 3) {
			run();
			int result = check();
			
			if(max < result) {
				max = result;
			}
			return;
		}
		
		for(int i=0; i<N; i++) {
			if(i < y)
				continue;
			
			for(int j=0; j<M; j++) {
				if(i==y && j<=x)
					continue;
				
				if(map[i][j] == 0) {
					map[i][j] = 1;
					dfs(j, i, cnt+1);
					map[i][j] = 0;
				}
			}
		}
	}

	static void run() {
		copymap = new int[N][M];
		
		for(int i=0; i<N; i++) {
			copymap[i] = Arrays.copyOf(map[i], M);
		}
		Queue<Point> q = new ArrayDeque<>();
		
		for(Point p: virus) {
			q.add(p);
		}
		
		while(!q.isEmpty()) {
			Point p = q.poll();
			
			for(int d=0; d<4; d++) {
				int nx = p.x + dx[d];
				int ny = p.y + dy[d];
				
				if(nx<0 || nx>=M || ny<0 || ny>=N || copymap[ny][nx]!=0)
					continue;
				
				copymap[ny][nx] = 2;
				q.add(new Point(nx, ny));
			}
		}
	}
	
	static int check() {
		int cnt = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(copymap[i][j] == 0) {
					cnt++;
				}
			}
		}
		
		return cnt;
	}
}
