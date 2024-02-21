import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int n, m;
	static int[] parents;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			
			parents = new int[n + 1];
			
			sb.append("#").append(t).append(" ");
			
			for(int i=1; i<=n; i++) {
				parents[i] = i;
			}
			
			for(int i=0; i<m; i++) {
				st = new StringTokenizer(br.readLine());
				int order = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				if(order == 0)
					union(a, b);
				else if(getParent(a) == getParent(b))
					sb.append(1);
				else
					sb.append(0);
			}
			
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	static int getParent(int a) {
		if(parents[a] == a)
			return a;
		return parents[a] = getParent(parents[a]);
	}

	static void union(int a, int b) {
		int pa = getParent(a);
		int pb = getParent(b);
		
		if(pa == pb)
			return;
		
		parents[pb] = pa;
	}
}
