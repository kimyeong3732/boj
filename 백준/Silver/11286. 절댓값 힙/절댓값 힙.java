import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		PriorityQueue<Integer> pq = new PriorityQueue<>((n1, n2) -> Math.abs(n1)==Math.abs(n2) ? n1-n2 : Math.abs(n1)-Math.abs(n2));
		
		int n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; i++) {
			int s = Integer.parseInt(br.readLine());
			
			if(s == 0) {
				if(pq.isEmpty())
					sb.append(0).append("\n");
				else
					sb.append(pq.poll()).append("\n");
			}
			else
				pq.offer(s);
		}
		
		System.out.println(sb);
	}
}
