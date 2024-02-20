import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int n, m, min_num = Integer.MAX_VALUE;
	static List<Point> house = new ArrayList<>();
	static List<Point> chicken = new ArrayList<>();
	static Point[] choose;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		choose = new Point[m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				int num = Integer.parseInt(st.nextToken());
				
				if(num == 1)
					house.add(new Point(j, i));
				else if(num == 2)
					chicken.add(new Point(j, i));
			}
		}
		
		comb(0, 0);
		
		System.out.println(min_num);
	}

	static void comb(int index, int cnt) {
		if(cnt == m) {
			check();
			return;
		}
		
		if(index == chicken.size()) {
			return;
		}
		
		choose[cnt] = chicken.get(index);
		comb(index+1, cnt+1);
		comb(index+1, cnt);
		
	}
	
	static void check() {
		int sum = 0;
		
		for(Point h: house) {
			int dis = Integer.MAX_VALUE;
			
			for(Point c: choose) {
				dis = Math.min(dis, Math.abs(h.x-c.x)+Math.abs(h.y-c.y));
			}
			
			sum += dis;
		}
		
		min_num = Math.min(min_num, sum);
	}
}
