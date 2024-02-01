import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		char[] str = br.readLine().toCharArray();
		
		int[] condition = new int[4];

		st = new StringTokenizer(br.readLine());
		for(int i=0; i<4; i++) {
			condition[i] = Integer.parseInt(st.nextToken());
		}
		
		int begin = 0;
		int end = m;
		int[] nums = new int[4];
		int result = 0;
		
		for(int i=begin; i<end; i++) {
			switch(str[i]) {
			case 'A':
				nums[0]++;
				break;
			case 'C':
				nums[1]++;
				break;
			case 'G':
				nums[2]++;
				break;
			case 'T':
				nums[3]++;
				break;
			}
		}
		
		if(check(condition, nums))
			result++;
		
		for(int i=0; i<n-m; i++) {
			switch(str[begin+i]) {
			case 'A':
				nums[0]--;
				break;
			case 'C':
				nums[1]--;
				break;
			case 'G':
				nums[2]--;
				break;
			case 'T':
				nums[3]--;
				break;
			}
			
			switch(str[end+i]) {
			case 'A':
				nums[0]++;
				break;
			case 'C':
				nums[1]++;
				break;
			case 'G':
				nums[2]++;
				break;
			case 'T':
				nums[3]++;
				break;
			}
			
			if(check(condition, nums))
				result++;
		}
		
		sb.append(result).append("\n");
		System.out.println(sb);
	}
	
	static boolean check(int[] condition, int[] nums) {
		for(int i=0; i<4; i++)
			if(condition[i] > nums[i])
				return false;
		
		return true;
	}
}
