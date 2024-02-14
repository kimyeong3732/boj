import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
	
	static char[][] image;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		image = new char[n][];
		
		for(int i=0; i<n; i++) {
			image[i] = br.readLine().toCharArray();
		}
		
		dfs(n, 0, 0);
		
		sb.append("\n");
		System.out.println(sb);
	}

	static void dfs(int n, int x, int y) {
		char find = image[y][x];
		boolean state = false;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(find != image[y+i][x+j]) {
					state = true;
					break;
				}
			}
			
			if(state)
				break;
		}
		
		if(!state) {
			sb.append(find);
			return;
		}
		
		int half = n / 2;
		
		sb.append("(");
		dfs(half, x, y);
		dfs(half, x+half, y);
		dfs(half, x, y+half);
		dfs(half, x+half, y+half);
		sb.append(")");
	}
}
