import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution {
	
	static int[][] map;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=n; i++) {
			int num = Integer.parseInt(br.readLine());
			snail(num);
			
			sb.append("#").append(i).append("\n");
			for(int j=0; j<num; j++) {
				for(int k=0; k<num; k++)
					sb.append(map[j][k]).append(" ");
				
				sb.append("\n");
			}
		}
		System.out.println(sb);
	}
	
	static void snail(int num) {
		map = new int[num][num];
		int x = -1;
		int y = 0;
		int dir = 0;
		int count = 1;
		int[] dx = {1, 0, -1, 0};
		int[] dy = {0, 1, 0, -1};
		
		
		for(int i=num; i>0; i--) {
			for(int j=0; j<i; j++) {
				x += dx[dir];
				y += dy[dir];
				map[y][x] = count++;
			}
			
			dir = (dir + 1) % 4;
			
			if(i != num) {
				for(int j=0; j<i; j++) {
					x += dx[dir];
					y += dy[dir];
					map[y][x] = count++;
				}
				
				dir = (dir + 1) % 4;
			}
		}
	}
}
