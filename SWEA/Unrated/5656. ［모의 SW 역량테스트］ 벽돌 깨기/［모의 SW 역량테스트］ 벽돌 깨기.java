import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Solution {

	static int N, M, NUM, result;
	static int[][] map;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			NUM = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			result = N * M;
			map = new int[N][M];
			
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			game(map, 0);
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

	static void game(int[][] input, int count) {
		if(count == NUM) {
			check(input);
			return;
		}
		
		for(int i=0; i<M; i++) {
			int[][] copyMap = new int[N][];
			for(int j=0; j<N; j++) {
				copyMap[j] = Arrays.copyOf(input[j], M);
			}
			
			doDrop(i, copyMap);
			game(copyMap, count+1);
		}
	}
	
	static void check(int[][] input) {
		int count = 0;
		
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(input[i][j] != 0)
					count++;
		
		result = Math.min(result, count);
	}
	
	static void doDrop(int x, int[][] input) {
		int y = 0;
		
		while(true) {
			if(y >= N)
				return;
			
			if(input[y][x] != 0)
				break;
			
			y++;
		}
		
		doBreak(x, y, input);
		doMove(input);
	}
	
	static void doBreak(int x, int y, int[][] input) {
		int power = input[y][x] - 1;
		input[y][x] = 0;
		
		for(int i=1; i<=power; i++) {
			for(int d=0; d<4; d++) {
				int nx = x + dx[d] * i;
				int ny = y + dy[d] * i;
				
				if(nx<0 || nx>=M || ny<0 || ny>=N || input[ny][nx]==0)
					continue;
				
				doBreak(nx, ny, input);
			}
		}
	}
	
	static void doMove(int[][] input) {
		for(int i=0; i<M; i++) {
			boolean zeroFind = false;
			int index = N - 1;
			
			for(int j=N-1; j>=0; j--) {
				if(!zeroFind && input[j][i]==0) {
					zeroFind = true;
					index = j;
				}
				
				else if(zeroFind && input[j][i]!=0) {
					input[index][i] = input[j][i];
					input[j][i] = 0;
					index--;
				}
			}
		}
	}
}