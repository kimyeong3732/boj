import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution {

	static int n, min;
	static int[][] map;
	static int[][] dis;
	static List<Point> peo, stair;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			n = Integer.parseInt(br.readLine());
			min = Integer.MAX_VALUE;
			map = new int[n][n];
			peo = new ArrayList<>();
			stair = new ArrayList<>();
			
			for(int i=0; i<n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					
					if(map[i][j] == 1) {
						peo.add(new Point(j, i));
					}
					else if(map[i][j] > 1) {
						stair.add(new Point(j, i));
					}
				}
			}
			
			dis = new int[peo.size()][2];
			
			for(int i=0; i<peo.size(); i++) {
				Point p = peo.get(i);
				for(int j=0; j<2; j++) {
					Point s = stair.get(j);
					dis[i][j] = Math.abs(p.x-s.x) + Math.abs(p.y-s.y);
				}
			}
			
			for(int i=0; i<(1<<peo.size()); i++) {
				min = Math.min(min, calTime(i));
			}
			
			sb.append("#").append(t).append(" ").append(min).append("\n");
		}
		System.out.println(sb);
	}

	static int calTime(int mask) {
		PriorityQueue<Integer> pq1 = new PriorityQueue<>();
		PriorityQueue<Integer> pq2 = new PriorityQueue<>();
		int[] cost = new int[] {map[stair.get(0).y][stair.get(0).x], map[stair.get(1).y][stair.get(1).x]};
		
		for(int i=0; i<peo.size(); i++) {
			if((mask&1<<i) == 0) {
				pq1.add(dis[i][0]);
			}
			else {
				pq2.add(dis[i][1]);
			}
		}
		
		int temp = 0;
		Queue<Integer> size = new ArrayDeque<>();
		
		while(!pq1.isEmpty()) {
			int num = pq1.poll();
			
			if(size.size() >= 3) {
				temp = size.poll();
			}
			
			if(num < temp) {
				num = temp;
			}
			
			size.add(num + cost[0]);
		}
		
		while(!size.isEmpty()) {
			temp = size.poll();
		}
		
		int result = temp + 1;
		
		temp = 0;
		
		while(!pq2.isEmpty()) {
			int num = pq2.poll();
			
			if(size.size() >= 3) {
				temp = size.poll();
			}
			
			if(num < temp) {
				num = temp;
			}
			
			size.add(num + cost[1]);
		}
		
		while(!size.isEmpty()) {
			temp = size.poll();
		}
		
		result = Math.max(result, temp+1);
		
		return result;
	}
}
