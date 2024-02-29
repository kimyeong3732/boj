import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

	static int N, max, mincost;
	static int[][] map;
	static List<Point> pro;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			max = 0;
			mincost = Integer.MAX_VALUE;
			map = new int[N][N];
			pro = new ArrayList<>();
			
			for(int i=0; i<N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					
					if(map[i][j] == 1) {
						if(i!=0 && i!=N-1 && j!=0 && j!=N-1) {
							pro.add(new Point(j, i));
						}
						else {
							max++;
						}
					}
				}
			}
			
			dfs(max, 0, 0);
			
			sb.append("#").append(t).append(" ").append(mincost).append("\n");
		}
		System.out.println(sb);
	}

	static void dfs(int count, int cost, int start) {
		if(start == pro.size()) {
			if(count >= max) {
				if(count==max && cost<mincost) {
					mincost = cost;
				}
				if(count > max) {
					max = count;
					mincost = cost;
				}
			}
			return;
		}
		
		if(count+pro.size()-start < max)
			return;
		
		int x = pro.get(start).x;
		int y = pro.get(start).y;
		for(int d=0; d<4; d++) {
			if(check(x, y, d)) {
				int cnt = run(x, y, d);
				dfs(count+1, cost+cnt, start+1);
				back(x, y, d);
			}
		}
		dfs(count, cost, start+1);
	}
	
	static boolean check(int x, int y, int d) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		while(true) {
			if(nx<0 || nx>=N || ny<0 || ny>=N) {
				return true;
			}
			
			if(map[ny][nx] == 1) {
				break;
			}
			
			nx += dx[d];
			ny += dy[d];
		}
		
		return false;
	}
	
	static int run(int x, int y, int d) {
		int cnt = 0;
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		while(true) {
			if(nx<0 || nx>=N || ny<0 || ny>=N) {
				return cnt;
			}
			
			map[ny][nx] = 1;
			cnt++;
			
			nx += dx[d];
			ny += dy[d];
		}
	}
	
	static void back(int x, int y, int d) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		while(true) {
			if(nx<0 || nx>=N || ny<0 || ny>=N) {
				return;
			}
			
			map[ny][nx] = 0;
			
			nx += dx[d];
			ny += dy[d];
		}
	}
}
