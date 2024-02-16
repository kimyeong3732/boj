import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int n;
	static boolean[][] edges;
	static boolean[] visited;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());
		
		edges = new boolean[n+1][n+1];
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			edges[a][b] = true;
			edges[b][a] = true;
		}
		
		visited = new boolean[n + 1];
		dfs(start);
		sb.append("\n");
		visited = new boolean[n + 1];
		bfs(start);
		sb.append("\n");

		System.out.println(sb);
	}

	static void dfs(int s) {
		visited[s] = true;
		sb.append(s).append(" ");
		
		for(int i=1; i<=n; i++)
			if(edges[s][i] && !visited[i])
				dfs(i);
	}
	
	static void bfs(int s) {
		Queue<Integer> q = new ArrayDeque<>();
		
		q.offer(s);
		visited[s] = true;
		
		while(!q.isEmpty()) {
			int node = q.poll();
			sb.append(node).append(" ");
			
			for(int i=0; i<=n; i++) {
				if(edges[node][i] && !visited[i]) {
					visited[i] = true;
					q.offer(i);
				}
			}
		}
	}
}
