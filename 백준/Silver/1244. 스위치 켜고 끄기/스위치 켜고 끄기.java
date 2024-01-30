import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	static int n;
	static int[] switchs;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		switchs = new int[n + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=1; i<=n; i++) {
			switchs[i] = Integer.parseInt(st.nextToken());
		}
		
		int m = Integer.parseInt(br.readLine());
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			
			int sex = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			
			if(sex == 1) {
				male(num);
			}
			else {
				female(num);
			}
		}
		
		for(int i=1; i<=n; i++) {
			sb.append(switchs[i]).append(" ");
			if(i%20 == 0) {
				sb.append("\n");
			}
		}
		
		System.out.println(sb);
	}
	
	static void male(int num) {
		for(int i=1; i*num<=n; i++) {
			switchs[i*num] = (switchs[i*num] + 1) % 2;
		}
	}
	
	static void female(int num) {
		int begin = num;
		int end = num;
		
		while(begin>1 && end<n) {
			if(switchs[begin-1] != switchs[end+1])
				break;
			
			begin--;
			end++;
		}
		
		for(int i=begin; i<=end; i++) {
			switchs[i] = (switchs[i] + 1) % 2;
		}
	}
}
