import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int n, x, k;
	static List<switching> switchs;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
        StringTokenizer st = new StringTokenizer(br.readLine());

        n =  Integer.parseInt(st.nextToken());
        x =  Integer.parseInt(st.nextToken());
        k =  Integer.parseInt(st.nextToken());

        switchs = new ArrayList<>();

        for(int i=0; i<k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            switchs.add(new switching(a, b));
        }

        yabawi();
		System.out.println(x);
	}
	
	static void yabawi() {
		for(switching s: switchs)
			if(s.n1==x || s.n2==x)
				x = s.n1==x ? s.n2 : s.n1;
	}
	
	static class switching {
		int n1, n2;
		switching(int n1, int n2) {
			this.n1 = n1;
			this.n2 = n2;
		}
	}
}
