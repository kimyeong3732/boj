import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N;
	static List<Point> nodes;
	static List<List<Integer>> adjList;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			
			nodes = new ArrayList<>();
			adjList = new ArrayList<>();
			for(int i=0; i<N+2; i++) {
				adjList.add(new ArrayList<>());
			}
			
			for(int i=0; i<N+2; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				
				for(int j=0; j<nodes.size(); j++) {
					if(Math.abs(nodes.get(j).x-x)+Math.abs(nodes.get(j).y-y) <= 1000) {
						adjList.get(j).add(i);
						adjList.get(i).add(j);
					}
				}
				
				nodes.add(new Point(x, y));
			}
			
			if(bfs()) {
				sb.append("happy\n");
			}
			else {
				sb.append("sad\n");
			}
		}
		
		System.out.println(sb);
	}

	static boolean bfs() {
		Queue<Integer> q = new ArrayDeque<>();
		boolean visit[] = new boolean[N+2];
		
		q.offer(0);
		visit[0] = true;
		
		while(!q.isEmpty()) {
			int node = q.poll();
			
			if(node == N+1) {
				return true;
			}
			
			for(int n: adjList.get(node)) {
				if(visit[n]) {
					continue;
				}
				
				visit[n] = true;
				q.add(n);
			}
		}
		
		return false;
	}
}
