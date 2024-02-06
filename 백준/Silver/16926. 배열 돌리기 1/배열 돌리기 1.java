import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	
	static int n, m, r;
	static int[][] map;
	static int[][] cmap;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		map = new int[n][m];
		cmap = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<r; i++)
			rotate();
		
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				sb.append(map[i][j]).append(" ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
	
	static void rotate() {
		int line = 1;
		
		while(line<=n/2 && line<=m/2) {
			for(int i=line-1; i<n-line; i++) {
				cmap[i+1][line-1] = map[i][line-1];
				cmap[i][m-line] = map[i+1][m-line];
			}
			for(int i=line-1; i<m-line; i++) {
				cmap[line-1][i] = map[line-1][i+1];
				cmap[n-line][i+1] = map[n-line][i];
			}
			line++;
		}
		
		if(line*2<n && line*2<m)
			cmap[line-1][line-1] = map[line-1][line-1];
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				map[i][j] = cmap[i][j];
	}
}
