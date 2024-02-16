import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

	static int N;
	static List<Integer> com;
	static int[][] taste;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			com = new ArrayList<>();
			taste = new int[N][N];
			int result = Integer.MAX_VALUE;
			
			makeCom(1, 1, 1);
			
			for(int i=0; i<N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=0; j<N; j++)
					taste[i][j] = Integer.parseInt(st.nextToken());
			}
			
			
			for(int i=0; i<com.size(); i++) {
				int a = getScore(com.get(i), false);
				int b = getScore(com.get(i), true);
				
				if(result > Math.abs(a-b))
					result = Math.abs(a-b);
			}
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}

	static void makeCom(int cnt, int start, int mask) {
		if(cnt == N/2) {
			com.add(mask);
			return;
		}
		
		for(int i=start; i<N; i++)
			makeCom(cnt+1, i+1, mask|1<<i);
	}
	
	static int getScore(int mask, boolean mode) {
		int[] arr = new int[N/2];
		int index = 0;
		
		for(int i=0; i<N; i++) {
			if(!mode && (mask&1<<i)==0)
				arr[index++] = i;
			else if(mode && (mask&1<<i)!=0)
				arr[index++] = i;
		}
		
		int result = 0;
		
		for(int i=0; i<N/2-1; i++) {
			for(int j=i+1; j<N/2; j++) {
				result += taste[arr[i]][arr[j]] + taste[arr[j]][arr[i]];
			}
		}
		
		return result;
	}
}
