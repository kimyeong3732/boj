import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> input = new PriorityQueue<>((e1, e2) -> e2-e1);
		List<Integer> result = new ArrayList<>();
		PriorityQueue<Integer> gcds = new PriorityQueue<>((e1, e2) -> e2-e1);
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<n*n; i++) {
			input.offer(Integer.parseInt(st.nextToken()));
		}
		
		while(result.size() < n) {
			while(!gcds.isEmpty() && gcds.peek()==input.peek()) {
				input.poll();
				gcds.poll();
			}
			
			int newnum = input.poll();
			
			for(int num: result) {
				int gcdnum = gcd(num, newnum);
				gcds.offer(gcdnum);
				gcds.offer(gcdnum);
			}
			
			result.add(newnum);
		}
		
		for(int num: result) {
			System.out.print(num + " ");
		}
	}

	static int gcd(int a, int b) {
		if(b == 0) {
			return a;
		}
		
		return gcd(b, a%b);
	}
}
