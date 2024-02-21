import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int n;
	static boolean[] visit;
	static boolean state;
	static List<List<Integer>> edges = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		visit = new boolean[n];
		
		for(int i=0; i<n; i++)
			edges.add(new ArrayList<>());

		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			edges.get(a).add(b);
			edges.get(b).add(a);
		}
		
		for(int i=0; i<n; i++) {
			dfs(i, 0);
			
			if(state)
				break;
		}
		
		if(state)
			System.out.println(1);
		else
			System.out.println(0);
	}

	static void dfs(int s, int cnt) {
		if(cnt == 4) {
			state = true;
			return;
		}
		
		for(int i: edges.get(s)) {
			if(visit[i])
				continue;
			
			visit[s] = true;
			dfs(i, cnt+1);
			visit[s] = false;
		}
	}
}
