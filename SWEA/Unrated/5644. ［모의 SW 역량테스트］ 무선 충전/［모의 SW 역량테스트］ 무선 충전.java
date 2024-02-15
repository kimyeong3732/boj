import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

	static BC[] bcs;
	static int[] dx = {0, 0, 1, 0, -1};
	static int[] dy = {0, -1, 0, 1, 0};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			
			bcs = new BC[a];
			int[] moveA = new int[m];
			int[] moveB = new int[m];
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<m; i++)
				moveA[i] = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			for(int i=0; i<m; i++)
				moveB[i] = Integer.parseInt(st.nextToken());
			
			for(int i=0; i<a; i++) {
				st = new StringTokenizer(br.readLine());
				bcs[i] = new BC(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			
			int ax = 1, ay = 1;
			int bx = 10, by = 10;
			int result = 0;
			
			result += check(ax, ay, bx, by, bcs);
			
			for(int i=0; i<m; i++) {
				ax += dx[moveA[i]];
				ay += dy[moveA[i]];
				bx += dx[moveB[i]];
				by += dy[moveB[i]];
				
				result += check(ax, ay, bx, by, bcs);
			}
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

	static int check(int ax, int ay, int bx, int by, BC[] bcs) {
		List<int[]> as = new ArrayList<>();
		List<int[]> bs = new ArrayList<>();
		int result = 0;
		
		for(int i=0; i<bcs.length; i++) {
			if(bcs[i].disCheck(ax, ay))
				as.add(new int[] {i, bcs[i].pow});
			if(bcs[i].disCheck(bx, by))
				bs.add(new int[] {i, bcs[i].pow});
		}
		Collections.sort(as, (a, b) -> a[1]==b[1] ? a[0]-b[0] : b[1]-a[1]);
		Collections.sort(bs, (a, b) -> a[1]==b[1] ? a[0]-b[0] : b[1]-a[1]);
		
		if(as.size()!=0 && bs.size()!=0) {
			if(as.size() <  bs.size()) {
				int id = as.get(0)[0];
				result += as.get(0)[1];
				
				if(bs.get(0)[0] == id)
					result += bs.get(1)[1];
				else
					result += bs.get(0)[1];
				
				if(as.size() > 1) {
					int temp = 0;
					id = bs.get(0)[0];
					temp += bs.get(0)[1];
					
					if(as.get(0)[0] == id)
						temp += as.get(1)[1];
					else
						temp += as.get(0)[1];
					
					if(temp > result)
						result = temp;
				}
			}
			else if(bs.size() < as.size()){
				int id = bs.get(0)[0];
				result += bs.get(0)[1];
				
				if(as.get(0)[0] == id)
					result += as.get(1)[1];
				else
					result += as.get(0)[1];
				
				if(bs.size() > 1) {
					int temp = 0;
					id = as.get(0)[0];
					temp += as.get(0)[1];
					
					if(bs.get(0)[0] == id)
						temp += bs.get(1)[1];
					else
						temp += bs.get(0)[1];
					
					if(temp > result)
						result = temp;
				}
			}
			else {
				if(as.size() == 1) {
					int id = as.get(0)[0];
					result += as.get(0)[1];
					if(bs.get(0)[0] != id)
						result += bs.get(0)[1];
				}
				else {
					int id = as.get(0)[0];
					result += as.get(0)[1];
					
					if(bs.get(0)[0] == id)
						result += bs.get(1)[1];
					else
						result += bs.get(0)[1];

					int temp = 0;
					id = bs.get(0)[0];
					temp += bs.get(0)[1];
					
					if(as.get(0)[0] == id)
						temp += as.get(1)[1];
					else
						temp += as.get(0)[1];
					
					if(temp > result)
						result = temp;
				}
			}
		}
		
		else if(as.size() != 0)
			result += as.get(0)[1];
		
		else if(bs.size() != 0)
			result += bs.get(0)[1];
		
		return result;
	}
}

class BC {
	int x, y;
	int dis;
	int pow;
	BC(int x, int y, int dis, int pow) {
		this.x = x;
		this.y = y;
		this.dis = dis;
		this.pow = pow;
	}
	public boolean disCheck(int x, int y) {
		return dis >= Math.abs(this.x-x) + Math.abs(this.y-y);
	}
}