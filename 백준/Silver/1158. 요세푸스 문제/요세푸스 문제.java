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
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n + 1];
		
		for(int i=1; i<n; i++) {
			arr[i] = i + 1;
		}
		arr[n] = 1;
		
		int cur = n;
		
		sb.append("<");
		
		while(arr[cur] != 0) {
			for(int i=0; i<m-1; i++) {
				cur = arr[cur];
			}
			
			sb.append(arr[cur]);
			
			if(arr[cur] != cur)
				sb.append(", ");
			
			int temp = arr[cur];
			arr[cur] = arr[temp];
			arr[temp] = 0;
		}
		
		sb.append(">\n");
		
		System.out.println(sb);
	}

}
