import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int[][] map = new int[100][100];
	static int dest;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<10; i++) {
			int T = Integer.parseInt(br.readLine());
			sb.append("#").append(T).append(" ");
			
			for(int j=0; j<100; j++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int k=0; k<100; k++) {
					map[j][k] = Integer.parseInt(st.nextToken());
					
					if(map[j][k] == 2)
						dest = k;
				}
			}
			
			ladder(dest, 99);
		}
		
		System.out.println(sb);
	}
	
	static int[] dx = {1, -1, 0};
	static int[] dy = {0, 0, -1};
	
	static void ladder(int x, int y) {
		if(y == 0) {
			sb.append(x).append("\n");
			return;
		}
		
		for(int i=0; i<3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>=0 && nx<100 && ny>=0 && ny<100 && map[ny][nx]==1) {
				map[ny][nx] = 0;
				ladder(nx, ny);
				return;
			}
		}
	}
}
