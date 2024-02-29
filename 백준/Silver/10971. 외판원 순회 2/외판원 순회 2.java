import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int N, min;
	static int[][] cost;
	static boolean[] visit;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		min = Integer.MAX_VALUE;
		cost = new int[N][N];
		visit = new boolean[N];
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		visit[0] = true;
		dfs(0, 0, 0);
		System.out.println(min);
	}

	static void dfs(int start, int cnt, int totalcost) {
		if(totalcost >= min) {
			return;
		}
		
		if(cnt == N-1) {
			if(cost[start][0] != 0) {
				totalcost += cost[start][0];
				
				if(min > totalcost) {
					min = totalcost;
				}
			}
			
			return;
		}
		
		for(int i=0; i<N; i++) {
			if(cost[start][i]==0 || visit[i])
				continue;
			
			visit[i] = true;
			dfs(i, cnt+1, totalcost+cost[start][i]);
			visit[i] = false;
		}
	}
}
