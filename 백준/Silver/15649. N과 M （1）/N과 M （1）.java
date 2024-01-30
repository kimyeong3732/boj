import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int m;
	static int[] arr = new int[8];
	static boolean[] visit = new boolean[8];
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(input.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		make(0);
	}

	static void make(int count) {
		if(count == m) {
			for(int i=0; i<m; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i=1; i<=n; i++) {
			if(!visit[i-1]) {
				visit[i-1] = true;
				arr[count] = i;
				make(count + 1);
				visit[i-1] = false;
			}
		}
	}
}
