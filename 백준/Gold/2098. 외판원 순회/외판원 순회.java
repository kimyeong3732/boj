import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	static int N;
	static int[][] cost;
	static int[][] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		cost = new int[N][N];
		dp = new int[1<<(N-1)][N-1];
		
		for(int i=0; i<1<<(N-1); i++)
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<N-1; i++) {
			if(cost[N-1][i] != 0)
				dp[0|1<<i][i] = cost[N-1][i];
		}
		
		for(int i=1; i<(1<<(N-1))-1; i++) {
			for(int j=0; j<N-1; j++) {
				if((i&1<<j) == 0) {
					for(int k=0; k<N-1; k++) {
						int num = dp[i][k];
						int c = cost[k][j];
						
						if(num!=Integer.MAX_VALUE && c!=0)
							dp[i|1<<j][j] = Math.min(dp[i|1<<j][j], num+c);
					}
				}
			}
		}
		
		int result = Integer.MAX_VALUE;
		
		for(int i=0; i<N-1; i++) {
			int num = dp[(1<<(N-1))-1][i];
			int c = cost[i][N-1];
			
			if(num!=Integer.MAX_VALUE && c!=0)
				result = Math.min(result, num+c);
		}
		
		System.out.println(result);
	}
}
