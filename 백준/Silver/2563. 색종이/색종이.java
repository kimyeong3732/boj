import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		
		boolean[][] map = new boolean[100][100];
		int count = 0;
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int sx = Integer.parseInt(st.nextToken());
			int sy = Integer.parseInt(st.nextToken());
			
			for(int j=sy; j<sy+10; j++) {
				for(int k=sx; k<sx+10; k++) {
					if(map[j][k])
						continue;
					
					map[j][k] = true;
					count++;
				}
			}
		}
		
		sb.append(count).append("\n");
		System.out.println(sb);
	}
}
