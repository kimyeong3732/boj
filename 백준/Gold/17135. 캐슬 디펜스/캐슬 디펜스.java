import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int n, m, d;
	static int[][] originMap;
	static int[][] gameMap;
	static int[] dx = {-1, 0, 1};
	static int[] dy = {0, -1, 0};
	static int[] arch = new int[3];
	static Point[] enemy = new Point[3];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		
		originMap = new int[n][m];
		gameMap = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				originMap[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int result = 0;
		
		for(int i=0; i<m-2; i++) {
			arch[0] = i;
			
			for(int j=i+1; j<m-1; j++) {
				arch[1] = j;
				
				for(int k=j+1; k<m; k++) {
					arch[2] = k;
					
					for(int l=0; l<n; l++) {
						gameMap[l] = Arrays.copyOf(originMap[l], m);
					}
					
					int temp = game();
					
					result = Math.max(result, temp); 
				}
			}
		}
		
		System.out.println(result);
	}

	static int game() {
		int result = 0;
		
		while(!isClear()) {
			find();
			result += kill();
			move();
		}
		
		return result;
	}
	
	static boolean isClear() {
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(gameMap[i][j] == 1)
					return false;
		
		return true;
	}
	
	static void find() {
		for(int i=0; i<3; i++) {
			Queue<Point> q = new ArrayDeque<>();
			
			q.offer(new Point(arch[i], n-1));
			
			boolean[][] visit = new boolean[n][m];
			
			while(!q.isEmpty()) {
				Point p = q.poll();
				
				if(check(p, i)) {
					enemy[i] = new Point(-1, -1);
					break;
				}
				
				if(gameMap[p.y][p.x] == 1) {
					enemy[i] = p;
					break;
				}
				
				for(int j=0; j<3; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					
					if(nx<0 || nx >=m || ny<0 || visit[ny][nx])
						continue;
					
					visit[ny][nx] = true;
					q.offer(new Point(nx, ny));
				}
			}
		}
	}
	
	static boolean check(Point p, int index) {
		return d < Math.abs(p.x-arch[index])+Math.abs(p.y-n);
	}
	
	static int kill() {
		int count = 0;
		
		for(int i=0; i<3; i++) {
			int x = enemy[i].x;
			int y = enemy[i].y;
			
			if(x<0 || y<0 || gameMap[y][x]==0)
				continue;
			
			gameMap[y][x] = 0;
			count++;
		}
		
		return count;
	}
	
	static void move() {
		for(int i=n-1; i>=0; i--) {
			for(int j=0; j<m; j++) {
				if(gameMap[i][j] == 1) {
					if(i != n-1)
						gameMap[i+1][j] = 1;
					
					gameMap[i][j] = 0;
				}
			}
		}
	}
}