import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<10; i++) {
			int n = Integer.parseInt(br.readLine());
			char[] str = br.readLine().toCharArray();
			int result = 1;
			
			Deque<Character> stack = new ArrayDeque<>();
			
			sb.append("#").append(i+1).append(" ");
			
			for(int j=0; j<n; j++) {
				switch(str[j]) {
				case ')':
					if(stack.peek() == '(')
						stack.pop();
					else
						result = 0;
					break;
				case '}':
					if(stack.peek() == '{')
						stack.pop();
					else
						result = 0;
					break;
				case ']':
					if(stack.peek() == '[')
						stack.pop();
					else
						result = 0;
					break;
				case '>':
					if(stack.peek() == '<')
						stack.pop();
					else
						result = 0;
					break;
				default:
					stack.push(str[j]);
				}
				
				if(result == 0)
					break;
			}
			
			if(!stack.isEmpty())
				result = 0;
			
			sb.append(result).append("\n");
		}
		
		System.out.println(sb);
	}
}
