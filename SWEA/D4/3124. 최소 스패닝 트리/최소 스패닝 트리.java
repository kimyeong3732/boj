import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Solution {

	static int n, e;
	static int[] parents;
	static edge[] edges;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			
			parents = new int[n + 1];
			edges = new edge[e];
			
			for(int i=0; i<e; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				edges[i] = new edge(a, b, c);
			}
			
			Arrays.sort(edges, (e1, e2) -> e1.cost-e2.cost);
			
			int cnt = 0;
			long sum = 0;
			
			reset();
			
			for(edge e: edges) {
				if(union(e.a, e.b)) {
					cnt++;
					sum += e.cost;
					if(cnt == n-1)
						break;
				}
			}
			
			sb.append("#").append(t).append(" ").append(sum).append("\n");
		}
		System.out.println(sb);
	}

	static void reset() {
		for(int i=1; i<=n; i++) {
			parents[i] = i;
		}
	}
	
	static int getParent(int a) {
		if(parents[a] == a)
			return a;
		return parents[a] = getParent(parents[a]);
	}
	
	static boolean union(int a, int b) {
		int pa = getParent(a);
		int pb = getParent(b);
		
		if(pa == pb)
			return false;
		
		parents[pb] = pa;
		return true;
	}
}

class edge {
	int a, b, cost;
	edge(int a, int b, int cost) {
		this.a = a;
		this.b = b;
		this.cost = cost;
	}
}
