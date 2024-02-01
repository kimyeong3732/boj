import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int t, n, m;
	static int[][] arr;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		t = Integer.parseInt(br.readLine());
		for(int i=0; i<t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			arr = new int[n+1][n+1];
	
			for(int j=1; j<=n; j++) {
				st = new StringTokenizer(br.readLine());
				for(int k=1; k<=n; k++) {
					arr[j][k] = arr[j][k-1] + Integer.parseInt(st.nextToken());
				}
			}
			
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					arr[k][j] += arr[k-1][j];
				}
			}
			
			int result = 0;
			
			for(int j=m; j<=n; j++) {
				for(int k=m; k<=n; k++) {
					result = Math.max(result, arr[j][k]-arr[j][k-m]-arr[j-m][k]+arr[j-m][k-m]);
				}
			}
			sb.append("#").append(i+1).append(" ").append(result).append("\n");
		}

		System.out.println(sb);
	}

}
