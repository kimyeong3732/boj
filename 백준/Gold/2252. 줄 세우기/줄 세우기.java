import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		List<List<Integer>> edges = new ArrayList<>();
		int[] parents = new int[n + 1];
		
		for(int i=0; i<=n; i++)
			edges.add(new ArrayList<>());
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			edges.get(a).add(b);
			parents[b]++;
		}

		Queue<Integer> q = new ArrayDeque<>();
		
		for(int i=1; i<=n; i++)
			if(parents[i] == 0)
				q.offer(i);
		
		while(!q.isEmpty()) {
			int node = q.poll();
			sb.append(node).append(" ");
			
			for(int i: edges.get(node)) {
				parents[i]--;
				
				if(parents[i] == 0)
					q.offer(i);
			}
		}
		
		sb.append("\n");
		System.out.println(sb);
	}

}
