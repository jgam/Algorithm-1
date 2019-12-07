package december02;

import java.util.Scanner;

public class ¿Ø±‚≥ÛπË√ﬂ_dfs_1012 {
	static int tc,c_cnt,n,m;
	static int [][]arr,visited;
	static void dfs(int row,int col) {
		int []x= {0,0,-1,1};
		int []y= {-1,1,0,0};
		int newX,newY;
		visited[row][col]=1;
		for(int i=0;i<4;i++) {
			newX=col+x[i];
			newY=row+y[i];
			if(0<=newX&&newX<m&&0<=newY&&newY<n) {
				//System.out.println(newX+","+newY);
				if(arr[newY][newX]==1&&visited[newY][newX]==0)dfs(newY,newX);
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
					System.out.println("hi");
					
					if(arr[j][k]==1&&visited[j][k]==0) {
						cnt++;
						dfs(j,k);
					}
				}
			}
			System.out.println(cnt);
			
		}
		
		
		
		

	}

}
