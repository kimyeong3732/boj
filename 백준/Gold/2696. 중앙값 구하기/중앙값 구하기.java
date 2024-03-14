import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=0; t<T; t++) {
			int n = Integer.parseInt(br.readLine());
			int mid = 0;
			PriorityQueue<Integer> minpq = new PriorityQueue<>((a, b) -> a>b ? a==b ? 0 : 1 : -1);
			PriorityQueue<Integer> maxpq = new PriorityQueue<>((a, b) -> b>a ? a==b ? 0 : 1 : -1);
			
			sb.append((n+1)/2).append("\n");
			
			for(int i=0; i<=n/10; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int nn = 10;
				
				if(i == n/10) {
					nn = n - i * 10;
				}
				
				for(int j=0; j<nn; j++) {
					if(i==0 && j==0) {
						mid = Integer.parseInt(st.nextToken());
					}
					else {
						int temp = Integer.parseInt(st.nextToken());
						
						if(temp > mid) {
							minpq.add(temp);
						}
						else {
							maxpq.add(temp);
						}
					}
					
					if(j%2 == 0) {
						while(minpq.size() != maxpq.size()) {
							if(minpq.size() > maxpq.size()) {
								maxpq.add(mid);
								mid = minpq.poll();
							}
							else {
								minpq.add(mid);
								mid = maxpq.poll();
							}
						}
						
						sb.append(mid).append(" ");
					}
				}
				
				if(i%2 == 1) {
					sb.setLength(sb.length()-1);
					sb.append("\n");
				}
			}
			
			if((n+1)/2%10 != 0 ) {
				sb.setLength(sb.length()-1);
				sb.append("\n");
			}
		}
		
		System.out.println(sb);
	}

}
