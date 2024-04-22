import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

class Main {

	static int n;
	static myPoint end;
	static char[][] map;
	static boolean[][][] visit;
	static int[] dx = {-1, 1, 0, 0, 0};
	static int[] dy = {0, 0, -1, 1, 0};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		map = new char[n][];
		visit = new boolean[n][n][2];
		
		for(int i=0; i<n; i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		end = findPoint('E');
		
		System.out.println(bfs());
	}
	
	static myPoint findPoint(char c) {
		int i = 0;
		int j = 0;
		
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				if(map[i][j] == c)
					break;
			if(j < n)
				break;
		}
		
		if(j<n-2 && map[i][j+1]==c)
			return new myPoint(j+1, i, 0);
		else
			return new myPoint(j, i+1, 1);
	}
	
	static int bfs() {
		Queue<myQueuePoint> q = new ArrayDeque<>();
		
		myPoint start = findPoint('B');
		visit[start.y][start.x][start.r] = true;
		
		q.offer(new myQueuePoint(start, 0));
		
		while(!q.isEmpty()) {
			myQueuePoint node = q.poll();
			
			if(node.p.x==end.x && node.p.y==end.y && node.p.r==end.r)
				return node.count;
			
			for(int i=0; i<5; i++) {
				int nx = node.p.x + dx[i];
				int ny = node.p.y + dy[i];
				int nr = node.p.r;
				
				if(i == 4) 
					nr = (nr + 1) % 2;
				
				if(check(nx, ny, nr, i) || visit[ny][nx][nr])
					continue;
				
				visit[ny][nx][nr] = true;
				q.offer(new myQueuePoint(new myPoint(nx, ny, nr), node.count+1));
			}
		}
		
		return 0;
	}
	
	static boolean check(int x, int y, int r, int mode) {
		if(mode < 2) {
			if(r == 0) {
				if(x<1 || x>=n-1 || map[y][x+dx[mode]]=='1')
					return true;
			}
			else {
				if(x<0 || x>=n)
					return true;
				
				for(int i=y-1; i<=y+1; i++)
					if(map[i][x] == '1')
						return true;
			}
		}
		else if(mode < 4) {
			if(r == 0) {
				if(y<0 || y>=n)
					return true;
				
				for(int i=x-1; i<=x+1; i++)
					if(map[y][i] == '1')
						return true;
			}
			else {
				if(y<1 || y>=n-1 || map[y+dy[mode]][x]=='1')
					return true;
			}
		}
		else {
			if(x<1 || x>=n-1 || y<1 || y>=n-1)
				return true;
			
			for(int i=y-1; i<=y+1; i++)
				for(int j=x-1; j<=x+1; j++)
					if(map[i][j] == '1')
						return true;
		}
		
		return false;
	}

	static class myPoint {
		int x, y, r;
		myPoint(int x, int y, int r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}
	}
	
	static class myQueuePoint {
		myPoint p;
		int count;
		myQueuePoint(myPoint p, int count) {
			this.p = p;
			this.count = count;
		}
	}
}
