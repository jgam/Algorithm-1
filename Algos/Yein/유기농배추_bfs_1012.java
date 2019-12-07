package december02;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
class Point{
	int x,y;
	
	Point(int y,int x){
		this.x=x;
		this.y=y;
	}
}

public class ¿Ø±‚≥ÛπË√ﬂ_bfs_1012 {

	static int tc,c_cnt,n,m;
	static int [][]arr,visited;
	static void bfs(int row,int col) {
		Queue<Point>q=new LinkedList<Point>();
		int []dx= {0,0,-1,1};
		int []dy= {-1,1,0,0};
		
		Point p1=new Point(row,col);
		q.add(p1);
		
		while(!q.isEmpty()) {
			Point p2=q.poll();
			visited[p2.y][p2.x]=1;
			
			for(int i=0;i<4;i++) {
				int new_x=p2.x+dx[i];
				int new_y=p2.y+dy[i];
				
				if(0<=new_x&&new_x<m&&0<=new_y&&new_y<n) {
					if(arr[new_y][new_x]==1&&visited[new_y][new_x]==0) {
						Point p3=new Point(new_y,new_x);
						q.add(p3);
						visited[p3.y][p3.x]=1;
						
					}
					
				}
				
			}
		}
		
		
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int x,y;
		
		tc=sc.nextInt();//tc
		
		for(int i=0;i<tc;i++) {
			int cnt=0;
			m=sc.nextInt();
			n=sc.nextInt();
			c_cnt=sc.nextInt();
			
			arr=new int[n+1][m+1];
			visited=new int[n+1][m+1];
			
			for(int j=0;j<c_cnt;j++) {
				x=sc.nextInt();
				y=sc.nextInt();
				
				arr[y][x]=1;
			}
			for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					
					
					if(arr[j][k]==1&&visited[j][k]==0) {
						cnt++;
						bfs(j,k);
					}
				}
			}
			System.out.println(cnt);
			
		}
		
		
		
		

	}

}

