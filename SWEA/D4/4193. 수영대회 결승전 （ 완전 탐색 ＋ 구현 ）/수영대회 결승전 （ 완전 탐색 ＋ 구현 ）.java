/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.util.PriorityQueue;

class Solution
{
	public static int BFS(int[][] map, int n, int sx, int sy, int ex, int ey)
	{
		int[][] visit = new int[n][n];
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
		
		pq.add(new int[] {sx, sy, 0});
		visit[sy][sx] = 1;
		
		int[] dx = new int[] {1, -1, 0, 0};
		int[] dy = new int[] {0, 0, 1, -1};
		
		while(!pq.isEmpty())
		{
			int[] point = pq.poll();
			int x = point[0];
			int y = point[1];
			int t = point[2];
			
			if(x==ex && y==ey)
			{
				return t;
			}
			
			for(int i=0; i<4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx>=0 && nx<n && ny>=0 && ny<n && map[ny][nx]!=1 && visit[ny][nx]==0)
	            {
	                visit[ny][nx] = 1;
	                
	                if(map[ny][nx]==2 && t%3!=2)
	                {
	                    int temp = (t / 3 + 1) * 3;
	                    pq.add(new int[]{nx, ny, temp});
	                }
	                else
	                {
	                    pq.add(new int[]{nx, ny, t+1});
	                }
	            }
			}
		}
		
		return -1;
	}
	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt();
            int[][] map = new int[n][n];
            
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    map[i][j] = sc.nextInt();
                }
            }
            
            int sy = sc.nextInt();
            int sx = sc.nextInt();
            int ey = sc.nextInt();
            int ex = sc.nextInt();
            
            System.out.printf("#%d %d\n", test_case, BFS(map, n, sx, sy, ex, ey));
		}
	}
}
