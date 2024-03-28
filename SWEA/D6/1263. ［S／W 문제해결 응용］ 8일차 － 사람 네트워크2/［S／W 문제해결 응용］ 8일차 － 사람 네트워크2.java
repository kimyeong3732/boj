import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int N;
	static int[][] mat;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			mat = new int[N][N];
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					int temp = Integer.parseInt(st.nextToken());
					
					if(i!=j && temp==0) {
						temp = 1000;
					}
					mat[i][j] = temp;
				}
			}
			
			floid();
			
			sb.append("#").append(t).append(" ").append(find()).append("\n");
		}

		System.out.println(sb);
	}
	
	static void floid() {
		for(int i=0; i<N; i++ ) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<N; k++) {
					mat[j][k] = Math.min(mat[j][k], mat[j][i] + mat[i][k]);
				}
			}
		}
	}
	
	static int find() {
		int result = 0;
		
		for(int i=1; i<N; i++) {
			result += mat[0][i];
		}
		
		for(int i=1; i<N; i++) {
			int local_sum = 0;
			
			for(int j=0; j<N; j++) {
                local_sum += mat[i][j];
			}
			
			if(result > local_sum) {
				result = local_sum;
			}
		}
		
		return result;
	}
}
