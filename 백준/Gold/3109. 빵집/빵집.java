import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int count;
	static int c, r;
	static char[][] map;
	static int[] dx = {1, 1, 1};
	static int[] dy = {-1, 0, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		map = new char[r][];
		
		for(int i=0; i<r; i++)
			map[i] = br.readLine().toCharArray();
		
		for(int i=0; i<r; i++)
			dfs(0, i);
		
		System.out.println(count);
	}

	static void dfs(int x, int y) {
		int save_cnt = count;
		
		for(int i=0; i<3; i++) {
			if(save_cnt != count)
				return;
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(ny<0 || ny>=r || map[ny][nx]=='x')
				continue;
			
			map[ny][nx] = 'x';
			
			if(nx == c-1)
				count++;
			
			if(save_cnt != count)
				return;
			
			dfs(nx, ny);
		}
	}
}
