import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<10; i++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			Deque<Integer> queue = new ArrayDeque<>();
			int decrease = 1;
			
			for(int j=0; j<8; j++)
				queue.offer(Integer.parseInt(st.nextToken()));
			
			while(queue.peek() > decrease) {
				queue.offer(queue.poll() - decrease);
				decrease++;
				if(decrease > 5)
					decrease = 1;
			}
			queue.poll();
			queue.offer(0);
			
			sb.append("#").append(i+1);
			for(int j=0; j<8; j++)
				sb.append(" ").append(queue.poll());
			sb.append("\n");
		}
		
		System.out.println(sb);
	}

}
