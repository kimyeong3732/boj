import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	static int n, m;
	static char[] alpha;
	static char[] pass;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		alpha = new char[m];
		pass = new char[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<m; i++) {
			alpha[i] = st.nextToken().charAt(0);
		}
		
		Arrays.sort(alpha);
		
		comb(0, 0);
		System.out.println(sb);
	}

	static void comb(int s, int cnt) {
		if(cnt == n) {
			if(check())
				sb.append(pass).append("\n");
			return;
		}
		
		for(int i=s; i<m-n+cnt+1; i++) {
			pass[cnt] = alpha[i];
			comb(i+1, cnt+1);
		}
	}
	
	static boolean check() {
		int count = 0;
		
		for(int i=0; i<n; i++)
			if(pass[i]=='a' || pass[i]=='e' || pass[i]=='i' || pass[i]=='o' || pass[i]=='u')
				count++;
		
		return count>0 && count<n-1;
	}
}
