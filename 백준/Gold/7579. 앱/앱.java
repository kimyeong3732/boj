import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		PriorityQueue<App> apps = new PriorityQueue<>((e1, e2) -> e1.cost-e2.cost);

		int temp[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			temp[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			apps.offer(new App(temp[i], Integer.parseInt(st.nextToken())));
		}
		
		int dp[][] = new int[10001][2];
		int state = 0;

		for (int i = 0; i <= N * 100; i++) {
			dp[i][1] = 0;
		}

		for (int i = 0; i < N; i++) {
			int other = (state + 1) % 2;
			App app = apps.poll();

			for (int j = 0; j <= N * 100; j++) {
				
				if (j<app.cost || dp[j][other]>=dp[j - app.cost][other]+app.m) {
					dp[j][state] = dp[j][other];
				}
				else {
					dp[j][state] = dp[j - app.cost][other] + app.m;
				}

				if (dp[j][state] >= M) {
					break;
				}
			}
			state = (state + 1) % 2;
		}
		state = (state + 1) % 2;
		
		for (int i = 0; i <= N * 100; i++) {
			if (dp[i][state] >= M) {
				System.out.println(i);
				break;
			}
		}
	}

	static class App {
		int m, cost;
		public App(int m, int cost) {
			this.m = m;
			this.cost = cost;
		}
	}
}
