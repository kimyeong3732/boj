import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	
	static int mod = 1234567891;
	static long[] fact;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			fact = new long[N + 1];
			
			fact[0] = 1;
			for(int i=1; i<=N; i++)
				fact[i] = fact[i-1] * i % mod;
			
			long result = fact[N] * (pow(fact[M], mod-2) * pow(fact[N-M], mod-2) % mod) % mod;
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

	static long pow(long n, int e) {
		if(e == 0)
			return 1;
		
		if(e%2 == 0)
			return pow(n*n%mod, e/2);
		
		return pow(n, e-1) * n % mod;
		
	}
}
