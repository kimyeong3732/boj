import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for(int t=0; t<T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int[][] comb = new int[n+1][k+1];
			
			comb[0][0] = 1;
			
			for(int i=0; i<=n; i++) {
				for(int j=0,end=Math.min(i,k); j<=end; j++) {
					if(j==0 || j==i) {
						comb[i][j] = 1;
					}
					else {
						comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
					}
				}
			}
			
			sb.append(comb[n][k]).append("\n");
		}
		System.out.println(sb);
	}

}
