import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int[] myTC, TC, perm;
	static int win, lose;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			myTC = new int[9];
			TC = new int[9];
			perm = new int[9];
			win = 0;
			lose = 0;
			int index = 0;
			
			for(int i=0; i<9; i++)
				myTC[i] = Integer.parseInt(st.nextToken());
			
			for(int i=1; i<=18; i++) {
				int j;
				for(j=0; j<9; j++)
					if(myTC[j] == i)
						break;
				
				if(j == 9)
					TC[index++] = i;
			}
			
			dfs(0, 0);
			sb.append("#").append(t).append(" ").append(win).append(" ").append(lose).append("\n");
		}
		
		System.out.println(sb);
	}

	static void dfs(int count, int mask) {
		if(count == 9) {
			int you = 0;
			int me = 0;
			for(int i=0; i<9; i++) {
				if(myTC[i] > perm[i])
					me += myTC[i] + perm[i];
				else
					you += myTC[i] + perm[i];
			}
			
			if(you > me)
				lose++;
			else if(me > you)
				win++;
			
			return;
		}
		
		for(int i=0; i<9; i++) {
			if((mask&1<<i) == 0) {
				perm[count] = TC[i];
				dfs(count+1, mask|1<<i);
			}
		}
	}
}
