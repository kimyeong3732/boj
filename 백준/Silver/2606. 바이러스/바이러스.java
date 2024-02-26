import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

// bfs 사용
// 소문을 알게 되는 사람들의 수에는 1번 사람 포함 X
class Main {

	static int n;
	static List<List<Integer>> edges;
	static boolean[] visit;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		visit = new boolean[n + 1]; // 0 dummy
		
		edges = new ArrayList<>();
		for(int i=0; i<=n; i++) {
			edges.add(new ArrayList<>());
		}
		
		for(int i=0; i<k; i++ ) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			edges.get(a).add(b);
			edges.get(b).add(a);
		}
		
		bfs();
		
		int count = 0;
		
		// 소문을 알게 되는 사람들에 1번 사람 포함 X
		for(int i=2; i<=n; i++) {
			if(visit[i]) {
				count++;
			}
		}
		
		System.out.println(count);
	}

	static void bfs() {
		Queue<Integer> q = new ArrayDeque<>();
		visit[1] = true;
		q.offer(1);
		
		while(!q.isEmpty()) {
			int num = q.poll();
			
			for(int i: edges.get(num)) {
				if(visit[i])
					continue;
				
				visit[i] = true;
				q.offer(i);
			}
		}
	}
}
