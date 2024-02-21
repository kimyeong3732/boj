import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int n, m, min_num = Integer.MAX_VALUE;
	static int[][] map;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static List<cctv> cctvs = new ArrayList<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
				if(map[i][j]>0 && map[i][j] <6)
					cctvs.add(new cctv(j, i, map[i][j]));
			}
		}
		
		comb(0);
		System.out.println(min_num);
	}
	
	static void comb(int cnt) {
		if(cnt == cctvs.size()) {
			int temp = run();
			
			min_num = Math.min(min_num, temp);
			
			return;
		}
		
		switch(cctvs.get(cnt).type) {
		case 1:
		case 3:
		case 4:
			cctvs.get(cnt).dir = 3;
			comb(cnt + 1);
			cctvs.get(cnt).dir = 2;
			comb(cnt + 1);
		case 2:
			cctvs.get(cnt).dir = 1;
			comb(cnt + 1);
		case 5:
			cctvs.get(cnt).dir = 0;
			comb(cnt + 1);
		}
	}

	static int run() {
		int[][] copy_map = new int[n][];
		
		for(int i=0; i<n; i++)
			copy_map[i] = Arrays.copyOf(map[i], m);
		
		for(cctv c: cctvs) {
			int x = c.x;
			int y = c.y;
			int t = c.type;
			int d = c.dir;
			int nx;
			int ny;
			
			switch(t) {
			case 1:
				nx = x;
				ny = y;
				while(true) {
					nx += dx[d];
					ny += dy[d];
					
					if(nx<0 || nx>=m || ny<0 || ny>=n || copy_map[ny][nx]==6)
						break;
					
					if(copy_map[ny][nx] == 0)
						copy_map[ny][nx] = -1;
				}
				break;
			case 2:
				for(int i=0; i<2; i++) {
					nx = x;
					ny = y;
					while(true) {
						nx += dx[(d+2*i)%4];
						ny += dy[(d+2*i)%4];
						
						if(nx<0 || nx>=m || ny<0 || ny>=n || copy_map[ny][nx]==6)
							break;
						
						if(copy_map[ny][nx] == 0)
							copy_map[ny][nx] = -1;
					}
				}
				break;
			case 3:
				for(int i=0; i<2; i++) {
					nx = x;
					ny = y;
					while(true) {
						nx += dx[(d+i)%4];
						ny += dy[(d+i)%4];
						
						if(nx<0 || nx>=m || ny<0 || ny>=n || copy_map[ny][nx]==6)
							break;
						
						if(copy_map[ny][nx] == 0)
							copy_map[ny][nx] = -1;
					}
				}
				break;
			case 4:
				for(int i=0; i<3; i++) {
					nx = x;
					ny = y;
					while(true) {
						nx += dx[(d+i)%4];
						ny += dy[(d+i)%4];
						
						if(nx<0 || nx>=m || ny<0 || ny>=n || copy_map[ny][nx]==6)
							break;
						
						if(copy_map[ny][nx] == 0)
							copy_map[ny][nx] = -1;
					}
				}
				break;
			case 5:
				for(int i=0; i<4; i++) {
					nx = x;
					ny = y;
					while(true) {
						nx += dx[i];
						ny += dy[i];
						
						if(nx<0 || nx>=m || ny<0 || ny>=n || copy_map[ny][nx]==6)
							break;
						
						if(copy_map[ny][nx] == 0)
							copy_map[ny][nx] = -1;
					}
				}
				break;
			}
		}
		int count = 0;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(copy_map[i][j] == 0)
					count++;
		
		return count;
	}
}

class cctv {
	int x, y;
	int type;
	int dir;
	cctv(int x, int y, int type) {
		this.x = x;
		this.y = y;
		this.type = type;
	}
}