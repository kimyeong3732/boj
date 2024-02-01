import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int total = 1 << n;
		int[] sarr = new int[n];
		int[] barr = new int[n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			sarr[i] = Integer.parseInt(st.nextToken());
			barr[i] = Integer.parseInt(st.nextToken());
		}
		
		int result = Integer.MAX_VALUE;
		
		for(int i=1; i<total; i++) {
			int s = 1;
			int b = 0;
			
			for(int j=0; j<n; j++) {
				if((i&1<<j) != 0) {
					s *= sarr[j];
					b += barr[j];
				}
			}
			
			result = Math.min(result, Math.abs(s-b));
		}
		
		sb.append(result).append("\n");
		System.out.println(sb);
	}
}