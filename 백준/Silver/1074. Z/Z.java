import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int count;
	static boolean z;
	static int tx, ty;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		ty = Integer.parseInt(st.nextToken());
		tx = Integer.parseInt(st.nextToken());
		
		find(n, 0, 0);
	}

	static void find(int n, int sx, int sy) {
		if(n == 0) {
			System.out.println(count);
			return;
		}
		
		int half = 1;
		for(int i=0; i<n-1; i++)
			half *= 2;
		
		if(tx<=sx+half-1 && ty<=sy+half-1)
			find(n-1, sx, sy);
		else if(tx>sx+half-1 && ty<=sy+half-1) {
			count += half * half;
			find(n-1, sx+half, sy);
		}
		else if(tx<=sx+half-1 && ty>sy+half-1) {
			count += half * half * 2;
			find(n-1, sx, sy+half);
		}
		else {
			count += half * half * 3;
			find(n-1, sx+half, sy+half);
		}
	}
}
