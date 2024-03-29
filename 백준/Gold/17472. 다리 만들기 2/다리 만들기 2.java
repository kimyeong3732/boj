import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N, M, NUM;
	static int[][] map;
	static int[] parents;
	static PriorityQueue<edge> edges = new PriorityQueue<>((e1, e2) -> e1.cost-e2.cost);
	static List<islandEdge> islandEdges = new ArrayList<>();
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		NUM = 0;
		map = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<M; j++) {
				int temp = Integer.parseInt(st.nextToken());
				
				if(temp > 0)
					temp = -1;
				
				map[i][j] = temp;
			}
		}
		
		init();
		kruskal();
	}
	
	static void init() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j] < 0) {
					bfs(j, i, ++NUM);
				}
			}
		}
		
		parents = new int[NUM + 1];
		for(int i=1; i<=NUM; i++) {
			parents[i] = i;
		}
		
		makeBridge();
	}
	
	static void bfs(int x, int y, int count) {
		Queue<Point> q = new ArrayDeque<>();
		
		q.offer(new Point(x, y));
		map[y][x] = count;
		
		while(!q.isEmpty()) {
			Point p = q.poll();
			
			for(int i=0; i<4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				
				if(nx<0 || nx>=M || ny<0 || ny>=N || map[ny][nx]>0)
					continue;
				
				if(map[ny][nx] == 0) {
					islandEdges.add(new islandEdge(p.x, p.y, i));
					continue;
				}
				
				map[ny][nx] = count;
				q.offer(new Point(nx, ny));
			}
		}
	}
	
	static void makeBridge() {
		for(islandEdge i: islandEdges) {
			int x = i.x;
			int y = i.y;
			int start = map[y][x];
			int len = 0;
			
			while(true) {
				x += dx[i.dir];
				y += dy[i.dir];
				
				if(x<0 || x>=M || y<0 || y>=N)
					break;
				
				if(map[y][x] != 0) {
					if(map[y][x]>start && len>1)
						edges.offer(new edge(start, map[y][x], len));
					
					break;
				}
				
				len++;
			}
		}
	}

	static void kruskal() {
		int result = 0;
		
		while(!edges.isEmpty()) {
			edge e = edges.poll();
			int ap = getParent(e.a);
			int bp = getParent(e.b);
			
			if(ap == bp)
				continue;
			
			unionParent(e.a, bp);
			result += e.cost;
		}
		
		int parentCheck = getParent(1);
		for(int i=2; i<=NUM; i++) {
			int temp = getParent(i);
			
			if(parentCheck != temp) {
				System.out.println(-1);
				return;
			}
		}
		
		System.out.println(result);
	}
	
	static int getParent(int num) {
		if(parents[num] == num)
			return num;
		
		return parents[num] = getParent(parents[num]);
	}
	
	static void unionParent(int node, int parent) {
		parents[getParent(node)] = parent;
	}
	
	static class edge {
		int a, b, cost;
		edge(int a, int b, int cost) {
			this.a = a;
			this.b = b;
			this.cost = cost;
		}
	}
	
	static class islandEdge {
		int x, y, dir;
		islandEdge(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}
}
