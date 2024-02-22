import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {

	static int n, min;
	static int[] people;
	static List<List<Integer>> edges;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		min = Integer.MAX_VALUE;
		
		people = new int[n];
		edges = new ArrayList<>();
		for(int i=0; i<n; i++) {
			edges.add(new ArrayList<>());
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<n; i++) {
			people[i] = Integer.parseInt(st.nextToken());
		}

		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			
			for(int j=0; j<m; j++) {
				edges.get(i).add(Integer.parseInt(st.nextToken())-1);
			}
		}
		
		for(int i=1; i<(1<<(n-1)); i++) {
			if(posible(i)) {
				min = Math.min(min, getNum(i));
			}
		}
		
		if(min == Integer.MAX_VALUE)
			min = -1;
		
		System.out.println(min);
	}

	static boolean posible(int mask) {
		int as = 0;
		int bs = 0;
		int num = 0;
		
		for(int i=0; i<n; i++) {
			if((mask&1<<i) == 0) {
				as = i;
				break;
			}
		}

		for(int i=0; i<n; i++) {
			if((mask&1<<i) != 0) {
				bs = i;
				break;
			}
		}

		for(int i=0; i<n; i++) {
			if((mask&1<<i) == 0) {
				num++;
			}
		}
		
		int acnt = 0;
		int bcnt = 0;
		boolean[] visit = new boolean[n];
		
		PriorityQueue<Integer> q = new PriorityQueue<>();
		
		q.add(as);
		visit[as] = true;
		while(!q.isEmpty()) {
			int a = q.poll();
			acnt++;
			
			for(int i: edges.get(a)) {
				if((mask&1<<i)==0 && !visit[i]) {
					visit[i] = true;
					q.add(i);
				}
			}
		}
		
		q.add(bs);
		visit[bs] = true;
		while(!q.isEmpty()) {
			int a = q.poll();
			bcnt++;
			
			for(int i: edges.get(a)) {
				if((mask&1<<i)!=0 && !visit[i]) {
					visit[i] = true;
					q.add(i);
				}
			}
		}
		
		return acnt==num && bcnt==n-num;
	}
	
	static int getNum(int mask) {
		int asum = 0;
		int bsum = 0;
		
		for(int i=0; i<n; i++) {
			if((mask&1<<i) == 0) {
				asum += people[i];
			}
			else {
				bsum += people[i];
			}
		}
		
		return Math.abs(asum - bsum);
	}
}
