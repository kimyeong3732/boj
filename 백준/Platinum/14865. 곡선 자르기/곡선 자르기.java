import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

// 모든 선분이 교차하지 않기 때문에 봉우리가 형성되기 위해선 반드시 x 축 기준으로 올라갔다가 내려와야한다.
// 도형이 그려지는 방향은 시계 방향이기 때문에 올라가는 선분부터 확인 하면 다음 선분은 반드시 내려간다. => 봉우리 시작점과 끝점 파악 가능
// 모든 선분이 교차하지 않기 때문에 봉우리의 범위가 겹쳤을 때
//		가장 바깥쪽에 있는 봉우리는 첫번째 조건 만족
//		가장 안쪽에 있는 봉우리는 두번때 조건 만족
class Main {

	static int n;
	static List<Mountain> ms = new ArrayList<>();;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Queue<ZeroXPoint> q = new ArrayDeque<>();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// 시작 위치
		int sx = Integer.parseInt(st.nextToken());
		int sy = Integer.parseInt(st.nextToken());
		
		// 이전 점의 y 값
		int by = sy;
		
		// n-1 개 점의 위치 입력
		for(int i=0; i<n-1; i++) {
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			// 이전 점과 입력 받은 점이 x 축을 지나는 경우
			if(y*by < 0) {
				int dir = (y-by) / Math.abs(y-by); // 방향값 1: 올라가는 방향, -1: 내려가는 방향
				q.offer(new ZeroXPoint(dir, x)); // 방향과 x 값 저장
			}
			
			by = y;
		}
		
		// 맨 처음 시작점과 맨 마지막 점의 선분이 x 축을 지나는 경우
		if(sy*by < 0) {
			int dir = (sy-by) / Math.abs(sy-by);
			q.offer(new ZeroXPoint(dir, sx));
		}
		
		// 올라가는 선분부터 나오도록 내려가는 선분이 가장 앞에 있을 시 가장 뒤에 넣는다.
		if(q.peek().dir < 0) {
			ZeroXPoint temp = q.poll();
			q.offer(temp);
		}
		
		// 봉우리 저장
		while(!q.isEmpty()) {
			ZeroXPoint z1 = q.poll();
			ZeroXPoint z2 = q.poll();
			
			if(z1.x > z2.x) {
				ms.add(new Mountain(z2.x, z1.x));
			}
			else {
				ms.add(new Mountain(z1.x, z2.x));
			}
		}
		
		// 저장된 봉우리를 시작점 기준으로 정렬
		Collections.sort(ms, (m1, m2) -> m1.s-m2.s);
		
		int counta = 0;
		int countb = 0;
		
		int lasta = Integer.MIN_VALUE;
		int lastb = Integer.MIN_VALUE;
		
		for(Mountain m: ms) {
			// 가장 바깥쪽 봉우리만 체크
			if(m.s > lasta) {
				counta++;
				lasta = m.e;
			}
			
			// 범위가 겹치지 않으면 count++
			if(m.s > lastb) {
				countb++;
				lastb = m.e;
			}
			
			// 범위가 겹치면 기준을 안쪽 봉우리로 수정
			if(m.s < lastb) {
				lastb = m.e;
			}
		}
		
		System.out.println(counta + " " + countb);
	}

	// 봉우리의 시작점과 끝점을 저장
	static class Mountain {
		int s, e;
		Mountain(int s, int e) {
			this.s = s;
			this.e = e;
		}
	}
	
	// x 축을 지났을때 x 값과 방향 저장
	static class ZeroXPoint {
		int dir, x;
		ZeroXPoint(int dir, int x) {
			this.dir = dir;
			this.x = x;
		}
	}
}
