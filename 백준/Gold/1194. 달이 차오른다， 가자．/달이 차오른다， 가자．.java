import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N, M;
	static char[][] map;
	static boolean[][][] visit;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N][];
		visit = new boolean[N][M][1<<6];
		
		for(int i=0; i<N; i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		BFS();
	}
	
	static void BFS() {
		Queue<myPosition> q = new ArrayDeque<>();
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j] == '0') {
					q.offer(new myPosition(j, i, 0, 0));
					visit[i][j][0] = true;
					break;
				}
			}
			if(!q.isEmpty())
				break;
		}
		
		while(!q.isEmpty()) {
			myPosition node = q.poll();
			
			if(map[node.y][node.x] == '1') {
				System.out.println(node.count);
				return;
			}
			
			int key = node.key;
			if(map[node.y][node.x]>='a' && map[node.y][node.x]<='f') {
				key = key | 1 << (map[node.y][node.x] - 'a');
			}
			
			for(int i=0; i<4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				
				if(nx<0 || nx>=M || ny<0 || ny>=N || visit[ny][nx][key] || map[ny][nx]=='#' || !keycheck(map[ny][nx], key))
					continue;
				
				visit[ny][nx][key] = true;
				q.offer(new myPosition(nx, ny, key, node.count+1));
			}
		}
		
		System.out.println(-1);
	}
	
	static boolean keycheck(char node, int key) {
		if(node>='A' && node<='F') {
			if((key&1<<(node-'A')) != 0)
				return true;
		
			return false;
		}
		
		return true;
	}

	static class myPosition {
		int x, y, key, count;
		myPosition(int x, int y, int key, int count) {
			this.x = x;
			this.y = y;
			this.key = key;
			this.count = count;
		}
	}
}
