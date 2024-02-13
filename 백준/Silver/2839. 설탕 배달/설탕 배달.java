import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		
		int five = n / 5;
		int rest = n % 5;
		
		while(rest%3 != 0) {
			if(five == 0) {
				sb.append(-1).append("\n");
				break;
			}
			five--;
			rest += 5;
		}
		
		if(rest%3 == 0)
			sb.append(five + rest / 3).append("\n");
		
		System.out.println(sb);
	}
}
