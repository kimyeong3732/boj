import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int n, count;
	static List<work> works = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		count = 0;
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int m1 = Integer.parseInt(st.nextToken());
			int d1 = Integer.parseInt(st.nextToken());
			int m2 = Integer.parseInt(st.nextToken());
			int d2 = Integer.parseInt(st.nextToken());
			
			works.add(new work(new date(m1, d1), new date(m2, d2)));
		}
		
		Collections.sort(works);
		
		date result = new date(11, 31);
		date temp = new date(12, 50);
		date endday = new date(3, 1);
		for(work w: works) {
			if(result.compareTo(endday) >= 0) {
				break;
			}
			if(w.end.compareTo(result) <= 0) {
				if(w.end.compareTo(temp) <= 0) {
					result = w.start.compareTo(result)>0 ? w.start : result;
				}
				else {
					temp = result;
					result = w.start.compareTo(result)>0 ? w.start : result;
					count++;
				}
			}
		}
		
		count = result.compareTo(endday)<0 ? 0 : count;
		
		System.out.println(count);
	}

	static class work implements Comparable<work> {
		date start, end;
		work(date start, date end) {
			this.start = start;
			this.end = end;
		}
		@Override
		public int compareTo(work o) {
			return o.end==end ? start.compareTo(o.start) : end.compareTo(o.end);
		}
	}
	
	static class date implements Comparable<date> {
		int m, d;
		date(int m, int d) {
			this.m = m;
			this.d = d;
		}
		@Override
		public int compareTo(date o) {
			return o.m==m ? o.d-d : o.m-m;
		}
	}
}
