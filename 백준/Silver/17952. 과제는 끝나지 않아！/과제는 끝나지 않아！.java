import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

// stack 사용
// 새로운 일이 들어올 경우 작업을 수행 후 시간이 모자라면 stack에 추가
// 새로운 일이 들어오지 않을 경우 stack 내부의 작업을 가져와 수행후 시간이 모자라면 stack에 추가
// 작업이 완료되면 평가 점수 상승
class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int score = 0;
		
		Stack<work> works = new Stack<>();
		
		for(int i=0; i<T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int order = Integer.parseInt(st.nextToken());
			int s = 0;
			int t = 0;
			
			// 새로운 작업이 들어오는 경우
			if(order == 1) {
				s = Integer.parseInt(st.nextToken());
				t = Integer.parseInt(st.nextToken());
			}
			// 기존의 작업이 존재하며 새로운 작업이 들어오지 않는 경우
			else if(!works.isEmpty()) {
				work w = works.pop();
				s = w.s;
				t = w.t;
			}
			
			// 해당 작업이 완료되지 않은 경우
			if(t > 1) {
				works.push(new work(s, t-1));
			}
			// 해당 작업이 완료된 경우 
			else {
				score += s;
			}
		}
		
		System.out.println(score);
	}

	// 평가 점수와 남은 작업 시간 저장
	static class work {
		int s, t;
		work(int s, int t) {
			this.s = s;
			this.t = t;
		}
	}
}
