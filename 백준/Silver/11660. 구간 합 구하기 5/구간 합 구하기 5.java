import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[][] arr;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n+1][n+1];

		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=n; j++) {
				arr[i][j] = arr[i][j-1] + Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				arr[j][i] += arr[j-1][i];
			}
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int ay = Integer.parseInt(st.nextToken());
			int ax = Integer.parseInt(st.nextToken());
			int by = Integer.parseInt(st.nextToken());
			int bx = Integer.parseInt(st.nextToken());
			
			int result = arr[by][bx] - arr[by][ax-1] - arr[ay-1][bx] + arr[ay-1][ax-1];
			sb.append(result).append("\n");
		}
		
		System.out.println(sb);
	}

}
