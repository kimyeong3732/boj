import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static long[] num = {0, 0, 1, 3, 6, 10, 15, 21, 28, 36};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			long result = 0;
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			long a = Long.parseLong(st.nextToken());
			long b = Long.parseLong(st.nextToken());
			
			for(long i=10; i/10<=b; i*=10) {
				long ma = a / i;
				long mb = b / i;
				long ra = a % i;
				long rb = b % i;
				
				result += ((45 * (mb - ma) * i) / 10);
				result -= (((num[(int)(ra/(i/10))] * i) / 10) + ((ra/(i/10)) * (ra%(i/10))));
				result += (((num[(int)(rb/(i/10))] * i) / 10) + ((rb/(i/10)) * ((rb%(i/10)) + 1)));
			}
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

}
