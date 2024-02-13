import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken());
		int l = Integer.parseInt(st.nextToken());
		int[] fruit = new int[n];

		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			fruit[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(fruit);
		int index = 0;
		
		while(index<n && l >= fruit[index]) {
			l++;
			index++;
		}

		sb.append(l).append("\n");
		
		System.out.println(sb);
	}
}
