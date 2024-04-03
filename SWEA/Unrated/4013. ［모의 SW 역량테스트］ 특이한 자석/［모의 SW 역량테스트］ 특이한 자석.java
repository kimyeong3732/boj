import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int[][] wheel;
	static int[] wheelIdx;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			int n = Integer.parseInt(br.readLine());
			
			wheel = new int[4][8];
			wheelIdx = new int[4];
			
			for(int i=0; i<4; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<8; j++) {
					wheel[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int i=0; i<n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int idx = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken());
				
				turnTotal(idx-1, dir);
			}
			
			int result = 0;
			for(int i=0; i<4; i++)
				result += wheel[i][wheelIdx[i]] * (1 << i);
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

	static void turnTotal(int idx, int dir) {
		if(idx > 0)
			turnLeft(idx-1, -dir);
		if(idx < 3)
			turnRight(idx+1, -dir);
		
		turn(idx, dir);
	}
	
	static void turnLeft(int idx, int dir) {
		int prev = (wheelIdx[idx+1] + 6) % 8;
		int now = (wheelIdx[idx] + 2) % 8;
		
		if((wheel[idx+1][prev]^wheel[idx][now]) == 1) {
			if(idx > 0)
				turnLeft(idx-1, -dir);
			
			turn(idx, dir);
		}
	}
	
	static void turnRight(int idx, int dir) {
		int prev = (wheelIdx[idx-1] + 2) % 8;
		int now = (wheelIdx[idx] + 6) % 8;
		
		if((wheel[idx-1][prev]^wheel[idx][now]) == 1) {
			if(idx < 3)
				turnRight(idx+1, -dir);
			
			turn(idx, dir);
		}
	}
	
	static void turn(int idx, int dir) {
		if(dir > 0)
			wheelIdx[idx] = (wheelIdx[idx] + 7) % 8;
		else
			wheelIdx[idx] = (wheelIdx[idx] + 1) % 8;
	}
}
