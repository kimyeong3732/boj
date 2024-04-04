import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int N, X, count;
	static int[] prev;
	static boolean[] install;
	static int[][] map;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			count = 0;
			
			map = new int[N][N];
			
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			find();
			
			sb.append("#").append(t).append(" ").append(count).append("\n");
		}
		
		System.out.println(sb);
	}
	
	static void find() {
		findRow();
		findCol();
	}
	
	static void input(int num) {
		for(int i=X-1; i>0; i--)
			prev[i] = prev[i-1];
		prev[0] = num;
	}
	
	static boolean check(int x, int y, boolean isRow) {
		if(prev[0]-map[y][x]!=1 && prev[0]-map[y][x]!=-1)
			return false;
		else {
			if(isRow) {
				if(map[y][x] > prev[0]) {
					for(int i=1; i<X; i++)
						if(prev[i] != prev[0])
							return false;
					
					for(int i=1; i<=X; i++)
						if(x-i<0 || install[x-i])
							return false;
					
					for(int i=1; i<=X; i++)
						install[x-i] = true;
				}
				else {
					for(int i=1; i<X; i++)
						if(x+i>=N || map[y][x+i] != map[y][x])
							return false;
					
					for(int i=0; i<X; i++)
						if(install[x+i])
							return false;
					
					for(int i=0; i<X; i++)
						install[x+i] = true;
				}
			}
			else {
				if(map[y][x] > prev[0]) {
					for(int i=1; i<X; i++)
						if(prev[i] != prev[0])
							return false;
					
					for(int i=1; i<=X; i++)
						if(y-i<0 || install[y-i])
							return false;
					
					for(int i=1; i<=X; i++)
						install[y-i] = true;
				}
				else {
					for(int i=1; i<X; i++)
						if(y+i>=N || map[y+i][x] != map[y][x])
							return false;
					
					for(int i=0; i<X; i++)
						if(install[y+i])
							return false;
					
					for(int i=0; i<X; i++)
						install[y+i] = true;
				}
			}
			
			return true;
		}
	}

	static void findRow() {
		for(int i=0; i<N; i++) {
			install = new boolean[N];
			prev = new int[X];
			int j = 0;
			
			for(; j<N; j++) {
				if(prev[0]!=0 && prev[0]!=map[i][j]) {
					if(!check(j, i, true))
						break;
				}
				input(map[i][j]);
			}
			
			if(j == N)
				count++;
		}
	}

	static void findCol() {
		for(int i=0; i<N; i++) {
			install = new boolean[N];
			prev = new int[X];
			int j = 0;
			
			for(; j<N; j++) {
				if(prev[0]!=0 && prev[0]!=map[j][i]) {
					if(!check(i, j, false))
						break;
				}
				input(map[j][i]);
			}
			
			if(j == N)
				count++;
		}
	}
}
