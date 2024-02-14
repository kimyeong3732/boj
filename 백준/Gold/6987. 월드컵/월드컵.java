import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	static boolean result;
	static team[] teams = new team[6];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<4; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			result = false;
			boolean single = false;
			int sum = 0;
			
			for(int j=0; j<6; j++) {
				teams[j] = new team(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
				
				sum += teams[j].win + teams[j].draw + teams[j].lose;
				
				if(!single && teams[j].win + teams[j].draw + teams[j].lose!=5)
					single = true;
			}
			
			if(single || sum!=30) {
				sb.append(0).append(" ");
				continue;
			}
			
			dfs(0, 1);
			
			if(result)
				sb.append(1).append(" ");
			else
				sb.append(0).append(" ");
		}
		
		sb.append("\n");
		System.out.println(sb);
	}
	
	static void dfs(int a, int b) {
		if(a == 5) {
			result = true;
			return;
		}
		
		int na = a;
		int nb = b + 1;
		if(nb == 6) {
			na++;
			nb = na + 1;
		}
		
		if(teams[a].win>0 && teams[b].lose>0) {
			teams[a].win--;
			teams[b].lose--;
			
			dfs(na, nb);
			
			teams[a].win++;
			teams[b].lose++;
		}
		
		if(teams[a].lose>0 && teams[b].win>0) {
			teams[a].lose--;
			teams[b].win--;
			
			dfs(na, nb);
			
			teams[a].lose++;
			teams[b].win++;
		}
		
		if(teams[a].draw>0 && teams[b].draw>0) {
			teams[a].draw--;
			teams[b].draw--;
			
			dfs(na, nb);
			
			teams[a].draw++;
			teams[b].draw++;
		}
	}
}

class team{
	int win, draw, lose;
	public team(int win, int draw, int lose) {
		this.win = win;
		this.draw = draw;
		this.lose = lose;
	}
}
