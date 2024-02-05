import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		Deque<poll> stack = new ArrayDeque<>();
		
		for(int i=0; i<n; i++) {
			int temp = Integer.parseInt(st.nextToken());
			while(!stack.isEmpty() && stack.peek().h<temp) {
				stack.pop();
			}
			
			if(stack.isEmpty())
				sb.append(0).append(" ");
			else
				sb.append(stack.peek().index).append(" ");
			stack.push(new poll(temp, i+1));
		}
		sb.append("\n");
		System.out.println(sb);
	}

}

class poll {
	int h;
	int index;
	
	poll(int h, int index) {
		this.h = h;
		this.index = index;
	}
}
