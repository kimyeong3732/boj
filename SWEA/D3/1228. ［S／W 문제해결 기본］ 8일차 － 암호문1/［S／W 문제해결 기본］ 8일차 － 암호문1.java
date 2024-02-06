import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.EmptyStackException;
import java.util.StringTokenizer;

class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int t=1; t<=10; t++) {
			myList ml = new myList();
			
			int n = Integer.parseInt(br.readLine());
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<n; i++) {
				ml.add(Integer.parseInt(st.nextToken()));
			}
			
			int m = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			
			for(int i=0; i<m; i++) {
				st.nextToken();
				int s = Integer.parseInt(st.nextToken());
				int sn = Integer.parseInt(st.nextToken());
				for(int j=0; j<sn; j++) {
					ml.insert(s+j, Integer.parseInt(st.nextToken()));
				}
			}
			
			sb.append("#").append(t).append(" ").append(ml.toString()).append("\n");
		}
		System.out.println(sb);
	}

}


class Node {
	public int data;
	public Node link;
	public Node() {}
	public Node(int data, Node link) {
		super();
		this.data = data;
		this.link = link;
	}
}

class myList {
	private Node top;
	
	public void add(int data) {
		Node end = goEnd();
		
		if(end == null)
			top = new Node(data, null);
		else
			end.link = new Node(data, null);
	}
	
	public void insert(int n, int data) {
		if(n == 0)
			top = new Node(data, top);
		else {
			Node cur = goTo(n);
			cur.link = new Node(data, cur.link);
		}
	}
	
	public boolean isEmpty() {
		return top == null;
	}
	
	public Node goTo(int n) {
		if(isEmpty()) throw new EmptyStackException();
		
		Node temp = top;
		for(int i=0; i<n-1; i++)
			temp = temp.link;
		
		return temp;
	}
	
	public Node goEnd() {
		if(isEmpty())
			return top;

		Node temp = top;
		while(temp.link != null)
			temp = temp.link;
		
		return temp;
	}
	
	@Override
	public String toString() {
		if(isEmpty())
			return null;
		
		StringBuilder sb = new StringBuilder();
		
		Node cur = top;
		int count = 0;
		
		while(cur!=null && count<10) {
			sb.append(cur.data).append(" ");
			cur = cur.link;
			count++;
		}
		sb.setLength(sb.length() - 1);
		
		return sb.toString();
	}
}