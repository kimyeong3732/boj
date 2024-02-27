import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

	static int v, e;
	static int[] cost;
	static List<List<Node>> edges = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		cost = new int[v + 1];
		
		Arrays.fill(cost, Integer.MAX_VALUE);
		
		for(int i=0; i<=v; i++) {
			edges.add(new ArrayList<>());
		}
		
		int s = Integer.parseInt(br.readLine());
		
		for(int i=0; i<e; i++) {
			st = new StringTokenizer(br.readLine());
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int value = Integer.parseInt(st.nextToken());
			
			edges.get(from).add(new Node(to, value));
		}
		
		dijkstra(s);

		for(int i=1; i<=v; i++) {
			if(cost[i] == Integer.MAX_VALUE) {
				sb.append("INF\n");
			}
			else {
				sb.append(cost[i]).append("\n");
			}
		}
		System.out.println(sb);
	}
	
	static void dijkstra(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<>((n1, n2) -> n1.value-n2.value);
		boolean[] visit = new boolean[v + 1];
		
		cost[start] = 0;
		pq.add(new Node(start, cost[start]));
		
		while(!pq.isEmpty()) {
			Node node = pq.poll();
			
			if(visit[node.node])
				continue;
			
			visit[node.node] = true;
			
			for(Node n: edges.get(node.node)) {
				if(visit[n.node])
					continue;
				
				cost[n.node] = Math.min(cost[n.node], node.value+n.value);
				pq.add(new Node(n.node, cost[n.node]));
			}
		}
	}

	static class Node {
		int node, value;
		Node(int node, int value) {
			this.node = node;
			this.value = value;
		}
	}
}
