import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int r, c;
	static int x, y;
	static char[][] map;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			x = -1;
			y = -1;
			
			map = new char[r][];
			
			for(int i=0; i<r; i++)
				map[i] = br.readLine().toCharArray();
			
			for(int i=0; i<r; i++) {
				for(int j=0; j<c; j++) {
					if(map[i][j]=='^' || map[i][j]=='v' || map[i][j]=='<' || map[i][j]=='>') {
						x = j;
						y = i;
						break;
					}
				}
				if(x!=-1 && y!=-1)
					break;
			}
			
			int n = Integer.parseInt(br.readLine());
			
			char[] cmd = br.readLine().toCharArray();
			
			for(int i=0; i<n; i++)
				game(cmd[i]);
			
			sb.append("#").append(t).append(" ");
			for(int i=0; i<r; i++)
				sb.append(map[i]).append("\n");
		}
		System.out.println(sb);
	}

	static void game(char cmd) {
		switch(cmd) {
		case 'U':
			map[y][x] = '^';
			
			if(y-1>=0 && map[y-1][x]=='.') {
				map[y-1][x] = '^';
				map[y][x] = '.';
				y--;
			}
			break;
			
		case 'D':
			map[y][x] = 'v';
			
			if(y+1<r && map[y+1][x]=='.') {
				map[y+1][x] = 'v';
				map[y][x] = '.';
				y++;
			}
			break;
			
		case 'L':
			map[y][x] = '<';
			
			if(x-1>=0 && map[y][x-1]=='.') {
				map[y][x-1] = '<';
				map[y][x] = '.';
				x--;
			}
			break;
			
		case 'R':
			map[y][x] = '>';
			
			if(x+1<c && map[y][x+1]=='.') {
				map[y][x+1] = '>';
				map[y][x] = '.';
				x++;
			}
			break;
			
		case 'S':
			int dx = 0;
			int dy = 0;
			switch(map[y][x]) {
			case '^':
				dx = 0;
				dy = -1;
				break;
			
			case 'v':
				dx = 0;
				dy = 1;
				break;
				
			case '<':
				dx = -1;
				dy = 0;
				break;
			
			case '>':
				dx = 1;
				dy = 0;
				break;
			}
			
			int nx = x;
			int ny = y;
			while(true) {
				nx += dx;
				ny += dy;
				
				if(nx<0 || nx>=c || ny<0 || ny>=r || map[ny][nx]=='#')
					break;
				if(map[ny][nx] == '*') {
					map[ny][nx] = '.';
					break;
				}
			}
		}
	}
}
