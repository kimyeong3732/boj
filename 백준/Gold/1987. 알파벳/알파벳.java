import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int n, m;
	static char[][] map;
	static int result = 0;
	static boolean[] alpha = new boolean[26];
	static boolean[][] visit;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new char[n][];
		visit = new boolean[n][m];
		
		for(int i=0; i<n; i++)
			map[i] = br.readLine().toCharArray();
		
		visit[0][0] = true;
		dfs(0, 0, 1);
		
		System.out.println(result);
	}

	static void dfs(int x, int y, int cnt) {
		int index = map[y][x] - 'A';

		if(alpha[index])
			return;
		
		if(result < cnt)
			result = cnt;
		
		alpha[index] = true;
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || nx>=m || ny<0 || ny>=n || visit[ny][nx])
				continue;
			
			visit[ny][nx] = true;
			dfs(nx, ny, cnt+1);
			visit[ny][nx] = false;
		}
		
		alpha[index] = false;
	}
}
