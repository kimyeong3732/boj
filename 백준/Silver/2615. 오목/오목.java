import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main {
	

	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		String[][] map = new String[19][];
		
		for(int i=0; i<19; i++) {
			map[i] = input.readLine().split(" ");
		}
		
		input.close();
		
		for(int i=0; i<19; i++) {
			for(int j=0; j<19; j++) {
				for(int k=0; k<4; k++) {
					if((Integer.parseInt(map[i][j])!=0) && find(map, i, j, k)) {
						System.out.println(map[i][j]);
						System.out.println((i+1) + " " + (j+1));
						return;
					}
				}
			}
		}
		
		System.out.println(0);	
	}
	
	public static boolean find(String[][] map, int y, int x, int mode) {
		int team = Integer.parseInt(map[y][x]);
		
		switch(mode) {
		case 0:
			if(x>14 || y > 14) {
				return false;
			}
			
			if(x>0 && y>0 && team==Integer.parseInt(map[y-1][x-1])) {
				return false;
			}
			
			for(int i=1; i<5; i++) {
				if(team != Integer.parseInt(map[y+i][x+i]))
					return false;
			}
			
			if(x<14 && y<14 && team==Integer.parseInt(map[y+5][x+5])) {
				return false;
			}
			
			return true;
			
		case 1:
			if(x > 14) {
				return false;
			}
			
			if(x>0 && team==Integer.parseInt(map[y][x-1])) {
				return false;
			}

			for(int i=1; i<5; i++) {
				if(team != Integer.parseInt(map[y][x+i]))
					return false;
			}

			if(x<14 && team==Integer.parseInt(map[y][x+5])) {
				return false;
			}
			return true;
			
		case 2:
			if(x>14 || y<4) {
				return false;
			}
			
			if(x>0 && y<18 && team==Integer.parseInt(map[y+1][x-1])) {
				return false;
			}

			for(int i=1; i<5; i++) {
				if(team != Integer.parseInt(map[y-i][x+i]))
					return false;
			}

			if(x<14 && y>4 && team==Integer.parseInt(map[y-5][x+5])) {
				return false;
			}
			return true;
		
		case 3:
			if(y > 14) {
				return false;
			}
			
			if(y>0 && team==Integer.parseInt(map[y-1][x])) {
				return false;
			}

			for(int i=1; i<5; i++) {
				if(team != Integer.parseInt(map[y+i][x]))
					return false;
			}

			if(y<14 && team==Integer.parseInt(map[y+5][x])) {
				return false;
			}
			return true;
			
		default:
			return false;
		}
		
	}
}

