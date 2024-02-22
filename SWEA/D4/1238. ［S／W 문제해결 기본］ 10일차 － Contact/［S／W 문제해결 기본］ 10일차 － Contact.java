import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution {

	static int n, s, last;
	static boolean[] visit;
	static List<List<Integer>> edges;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int t=1; t<=10; t++ ) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			n /= 2;
			
			visit = new boolean[100];
			
			edges = new ArrayList<>();
			for(int i=0; i<100; i++) {
				edges.add(new ArrayList<>());
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<n; i++) {
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				
				edges.get(from-1).add(to-1);
			}
			
			bfs();
			
			sb.append("#").append(t).append(" ").append(last+1).append("\n");
		}

		System.out.println(sb);
	}

	static void bfs() {
		last = s - 1;
		int lastcnt = 0;
		
		Queue<point> q = new ArrayDeque<>();
		
		q.offer(new point(last, 0));
		visit[last] = true;
		
		while(!q.isEmpty()) {
			point p = q.poll();
			
			if(p.cnt!=lastcnt || (p.cnt==lastcnt && last<p.num)) {
				lastcnt = p.cnt;
				last = p.num;
			}
			
			for(int i: edges.get(p.num)) {
				if(visit[i])
					continue;
				visit[i] = true;
				q.offer(new point(i, p.cnt+1));
			}
		}
	}
}

class point {
	int num, cnt;
	point(int num, int cnt) {
		this.num = num;
		this.cnt = cnt;
	}
}
