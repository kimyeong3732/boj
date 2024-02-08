import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			int result = 0;
			
			int[] score = new int[n];
			int[] cal = new int[n];
			
			for(int i=0; i<n; i++) {
				st = new StringTokenizer(br.readLine());
				score[i] = Integer.parseInt(st.nextToken());
				cal[i] = Integer.parseInt(st.nextToken());
			}
			
			for(int i=0; i<n; i++) {
				int[] comb = new int[n];
				for(int j=n-1; j>=n-1-i; j--) {
					comb[j] = 1;
				}
				
				do {
					int ssum = 0;
					int csum = 0;
					for(int k=0; k<n; k++) {
						if(comb[k] == 1) {
							ssum += score[k];
							csum += cal[k];
						}
						
						if(csum > l)
							break;
					}
					if(csum > l)
						continue;
					
					if(ssum > result)
						result = ssum;
				} while(np(comb));
			}
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
	
	static boolean np(int[] array) {
		int i = array.length - 1;
		while(i>0 && array[i-1]>=array[i])
			i--;
		
		if(i == 0)
			return false;
		
		int j = array.length - 1;
		while(array[i-1] >= array[j])
			j--;
		swap(array, i-1, j);
		
		int k = array.length - 1;
		while(i < k)
			swap(array, i++, k--);
		
		return true;
	}
	
	static void swap(int[] array, int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
