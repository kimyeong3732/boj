import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Main {
	
	static int N;
	static myPoint start;
	static List<myPoint> list;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		start = new myPoint(40000, 40000);
		list = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long x = Long.parseLong(st.nextToken());
			long y = Long.parseLong(st.nextToken());
			
			if(start.y>y || (start.y==y&&start.x>x)) {
				start.x = x;
				start.y = y;
			}
			
			list.add(new myPoint(x, y));
		}
		
		Collections.sort(list, (p1, p2) -> {
			int result = ccw(start, p2, p1);
			
			if(result == 0)
				return dis(start, p1)-dis(start, p2)<0 ? -1 : 1;
			
			return result;
			});
		
		convexHull();
	}

	static int ccw(myPoint a, myPoint b, myPoint c) {
		long result = a.x*b.y + b.x*c.y + c.x*a.y - (b.x*a.y + c.x*b.y + a.x*c.y);
		
		if(result == 0)
			return 0;
		
		return result<0 ? 1 : -1;
	}
	
	static long dis(myPoint a, myPoint b) {
		return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	}
	
	static void convexHull() {
		ArrayDeque<myPoint> s = new ArrayDeque<>();
		myPoint temp = start;
		
		s.push(new myPoint(start.x-1, start.y));
		
		for(myPoint p: list) {
			while(ccw(s.peek(), temp, p)<=0 && s.size()>1) {
				temp = s.poll();
			}
			
			s.push(temp);
			temp = p;
		}
		
		System.out.println(s.size());
	}
	
	static class myPoint {
		long x, y;
		myPoint(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}
}
