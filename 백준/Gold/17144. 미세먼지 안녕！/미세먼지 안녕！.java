import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int N, M, total;
	static int[][] map;
	static List<Integer> cleaner;
	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {-1, 0, 1, 0};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken());
		
		total = 0;
		map = new int[N][M];
		cleaner = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<M; j++) {
				int temp = Integer.parseInt(st.nextToken());
				
				if(temp < 0)
					cleaner.add(i);
				else if(temp > 0)
					total += temp;
				
				map[i][j] = temp;
			}
		}
		
		for(int i=0; i<T; i++)
			run();
		
		System.out.println(total);
	}

	static void run() {
		dust();
		clean();
	}
	
	static void dust() {
		int[][] newMap = new int[N][M];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				int temp = map[i][j];
				
				if(temp >= 5) {
					int sub = 0;
					for(int d=0; d<4; d++) {
						int nx = j + dx[d];
						int ny = i + dy[d];
						
						if(nx<0 || nx>=M || ny<0 || ny>=N || map[ny][nx]==-1)
							continue;
						
						newMap[ny][nx] += temp / 5;
						sub += temp / 5;
					}
					temp -= sub;
				}
				
				newMap[i][j] += temp;
			}
		}
		
		for(int i=0; i<N; i++)
			map[i] = Arrays.copyOf(newMap[i], M);
	}
	
	static void clean() {
		int up = cleaner.get(0);
		int down = cleaner.get(1);
		int x;
		int y;
		
		x = 0;
		y = up - 1;
		total -= map[y][x];
		
		for(int i=0; i<4; i++) {
			while(true) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx<0 || nx>=M || ny<0 || ny>up || map[ny][nx]==-1)
					break;
				
				map[y][x] = map[ny][nx];
				y = ny;
				x = nx;
			}
		}
		
		map[y][x] = 0;
		
		x = 0;
		y = down + 1;
		total -= map[y][x];
		
		for(int i=0; i<4; i++) {
			int dir = (6 - i) % 4;
			
			while(true) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx<0 || nx>=M || ny<down || ny>=N || map[ny][nx]==-1)
					break;
				
				map[y][x] = map[ny][nx];
				y = ny;
				x = nx;
			}
		}

		map[y][x] = 0;
	}
}
