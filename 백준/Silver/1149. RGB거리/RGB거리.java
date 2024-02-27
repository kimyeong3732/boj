import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int n;
	static int[][] cost;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		cost = new int[n][3];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<3; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int[][] dp = new int[n][3];
		
		for(int i=0; i<3; i++) {
			dp[0][i] = cost[0][i];
		}
		
		for(int i=1; i<n; i++) {
			for(int j=0; j<3; j++) {
				dp[i][j] = cost[i][j] + Math.min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
			}
		}
		
		System.out.println(Math.min(dp[n-1][0], Math.min(dp[n-1][1], dp[n-1][2])));
	}

}
