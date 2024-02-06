import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=1; i<=10; i++) {
			int n = Integer.parseInt(br.readLine());
			int result = 1;
			
			for(int j=1; j<=n; j++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				if(j*2+1 <= n) {
					st.nextToken();
					
					if(Character.isDigit(st.nextToken().charAt(0)))
						result = 0;
					
					st.nextToken();
					st.nextToken();
				}
				else if(j*2 <= n) {
					result = 0;

					st.nextToken();
					st.nextToken();
					st.nextToken();
				}
				else {
					st.nextToken();
					if(!Character.isDigit(st.nextToken().charAt(0)))
						result = 0;
				}
			}
			
			sb.append("#").append(i).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

}
