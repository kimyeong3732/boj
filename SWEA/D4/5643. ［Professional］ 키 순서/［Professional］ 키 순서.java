import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution {

	static int N, M;
	static boolean[] find;
	static List<List<Integer>> win, lose;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			
			win = new ArrayList<>();
			lose = new ArrayList<>();
			for(int i=0; i<N; i++) {
				win.add(new ArrayList<>());
				lose.add(new ArrayList<>());
			}
			
			for(int i=0; i<M; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int l = Integer.parseInt(st.nextToken()) - 1;
				int w = Integer.parseInt(st.nextToken()) - 1;
				
				win.get(w).add(l);
				lose.get(l).add(w);
			}
			
			int result = 0;
			for(int i=0; i<N; i++)
				if(check(i))
					result++;
			
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		
		System.out.println(sb);
	}

	static boolean check(int num) {
		int count = 1;
		find = new boolean[N];
		
		find[num] = true;
		
		Queue<Integer> q = new ArrayDeque<>();
		
		q.offer(num);
		
		while(!q.isEmpty()) {
			int node = q.poll();
			
			for(int i: lose.get(node)) {
				if(find[i])
					continue;
				find[i] = true;
				q.offer(i);
				count++;
			}
		}
		
		q.offer(num);
		
		while(!q.isEmpty()) {
			int node = q.poll();
			
			for(int i: win.get(node)) {
				if(find[i])
					continue;
				find[i] = true;
				q.offer(i);
				count++;
			}
		}
		
		return count == N;
	}
}
