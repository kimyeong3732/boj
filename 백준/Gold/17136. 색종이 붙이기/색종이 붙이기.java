import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int min = -1;
	static int targets = 0;
	static int[] nums = {0, 5, 5, 5, 5, 5};
	static int[][] map = new int[10][10];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<10; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<10; j++) {
				int temp = Integer.parseInt(st.nextToken());
				targets += temp;
				map[i][j] = temp;
			}
		}
		
		find(0);
		
		System.out.println(min);
	}

	static void find(int count) {
		if(targets == 0) {
			if(min<0 || min>count)
				min = count;
			return;
		}
		
		int x = -1;
		int y = -1;
		
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				if(map[i][j] == 1) {
					x = j;
					y = i;
					break;
				}
			}
			if(x>=0 && y>=0)
				break;
		}
		
		if(nums[5]>0 && check(x, y, 5)) {
			kill(x, y, 5);
			targets -= 25;
			nums[5]--;
			find(count+1);
			revive(x, y, 5);
			targets += 25;
			nums[5]++;
		}
		
		if(nums[4]>0 && check(x, y, 4)) {
			kill(x, y, 4);
			targets -= 16;
			nums[4]--;
			find(count+1);
			revive(x, y, 4);
			targets += 16;
			nums[4]++;
		}
		
		if(nums[3]>0 && check(x, y, 3)) {
			kill(x, y, 3);
			targets -= 9;
			nums[3]--;
			find(count+1);
			revive(x, y, 3);
			targets += 9;
			nums[3]++;
		}
		
		if(nums[2]>0 && check(x, y, 2)) {
			kill(x, y, 2);
			targets -= 4;
			nums[2]--;
			find(count+1);
			revive(x, y, 2);
			targets += 4;
			nums[2]++;
		}
		
		if(nums[1]>0) {
			kill(x, y, 1);
			targets -= 1;
			nums[1]--;
			find(count+1);
			revive(x, y, 1);
			targets += 1;
			nums[1]++;
		}
	}
	
	static boolean check(int x, int y, int num) {
		for(int i=0; i<num; i++)
			for(int j=0; j<num; j++)
				if(y+i>=10 || x+j>=10 || map[y+i][x+j] == 0)
					return false;
		
		return true;
	}
	
	static void kill(int x, int y, int num) {
		for(int i=0; i<num; i++)
			for(int j=0; j<num; j++)
				map[y+i][x+j] = 0;
	}
	
	static void revive(int x, int y, int num) {
		for(int i=0; i<num; i++)
			for(int j=0; j<num; j++)
				map[y+i][x+j] = 1;
	}
}
