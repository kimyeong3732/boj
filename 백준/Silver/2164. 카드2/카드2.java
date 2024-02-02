import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Deque<Integer> queue = new ArrayDeque<>();
		
		int n = Integer.parseInt(br.readLine());

		queue.clear();
		for(int i=1; i<=n; i++) {
			queue.offer(i);
		}
		
		while(queue.size() > 1) {
			queue.poll();
			queue.offer(queue.poll());
		}
		
		sb.append(queue.poll()).append("\n");
		System.out.println(sb);
	}

}
