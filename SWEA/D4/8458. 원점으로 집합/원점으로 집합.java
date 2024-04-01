import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			int n = Integer.parseInt(br.readLine());
			int max = 0;
			boolean[] even = new boolean[n];
			
			for(int i=0; i<n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				even[i] = (Math.abs(a) + Math.abs(b)) % 2 == 0;
				max = Math.max(max, Math.abs(a) + Math.abs(b));
			}
			
			int count = 0;
			int num = 0;
			while(num < max) {
				count++;
				num += count;
			}
			
			sb.append("#").append(t).append(" ");
			
			boolean numeven = num % 2 == 0;
			boolean state = true;
			for(int i=0; i<3; i++) {
				state = true;
				
				for(int j=0; j<n; j++) {
					if(numeven ^ even[j])
						even[j] = false;
					else
						even[j] = true;
				}
				
				for(int j=0; j<n; j++) {
					if(!even[j])
						state = false;
					
					if(!state)
						break;
				}
				
				if(state) {
					sb.append(count+i);
					break;
				}
				
				numeven = (count + i + 1) % 2 == 0;
			}
			
			if(!state)
				sb.append(-1);
			
			sb.append("\n");
		}
		
		System.out.println(sb);
	}

}
