import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int n, last, subresult;
	static int result;
	static position[] p;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			n = Integer.parseInt(br.readLine());
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			position office = new position(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			position home = new position(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			
			p = new position[n + 2];
			
			p[0] = office;
			p[n+1] = home;
			for(int i=1; i<=n; i++)
				p[i] = new position(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			
			result = Integer.MAX_VALUE;
			last = 0;
			subresult = 0;
			dfs(0, 0);
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}

	static void dfs(int cnt, int mask) {
		if(cnt == n) {
			subresult += p[last].dis(p[n+1]);
			
			if(result > subresult)
				result = subresult;
			
			subresult -= p[last].dis(p[n+1]);
			return;
		}
		
		int savelast = last;
		
		for(int i=1; i<=n; i++) {
			if((mask&1<<i) == 0) {
				subresult += p[last].dis(p[i]);
				last = i;
				dfs(cnt+1, mask|1<<i);
				last = savelast;
				subresult -= p[last].dis(p[i]);
			}
		}
	}
}

class position {
	int x, y;
	public position(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public int dis(position o) {
		return Math.abs(x-o.x) + Math.abs(y-o.y);
	}
}