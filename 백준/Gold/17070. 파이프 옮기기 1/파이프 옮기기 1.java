import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int n;
	static int[][] map;
	static int count = 0;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dfs(new Node(1, 0, 1));
		
		System.out.println(count);
	}
	
	static void dfs(Node node) {
		int x = node.x;
		int y = node.y;
		int dir = node.dir;
		
		if(x==n-1 && y==n-1) {
			count++;
			return;
		}
		
		if(x+1<n && map[y][x+1]==0 && (dir==1 || dir==2))
			dfs(new Node(x+1, y, 1));
		
		if(x+1<n && y+1<n && map[y][x+1]==0 && map[y+1][x]==0 && map[y+1][x+1]==0)
			dfs(new Node(x+1, y+1, 2));
		
		if(y+1<n && map[y+1][x]==0 && (dir==2 || dir==3))
			dfs(new Node(x, y+1, 3));
	}

	static class Node {
		int x, y, dir;
		public Node(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}
}
