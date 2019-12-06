package december02;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ¼û¹Ù²ÀÁú_1697 {
	static int bfs(int n,int k) {
		Queue q=new LinkedList();
		int[]map=new int[100001];//save the step and check the visiting
		Arrays.fill(map,-1);//initialize all steps to -1 -> -1==not visited
		
		int cur_loc=n; //current location
		
		map[cur_loc]=0;//visited & it takes 0 step 
		q.add(n);
		
		while(!q.isEmpty()) {
			cur_loc=(int) q.poll();
			
			if(cur_loc==k) {//Subin is in sister's location
				return map[cur_loc];
			}
			
			if(cur_loc-1>=0&&map[cur_loc-1]==-1) {//Subin moved back step
				map[cur_loc-1]=map[cur_loc]+1;
				q.add(cur_loc-1);
			}
			
			if(cur_loc+1<=100000&&map[cur_loc+1]==-1) {//Subin moved front step
				map[cur_loc+1]=map[cur_loc]+1;
				q.add(cur_loc+1);
			}
			if(cur_loc*2<=100000&&map[cur_loc*2]==-1) {//Subin jumped to twice of hers
				map[cur_loc*2]=map[cur_loc]+1;
				q.add(cur_loc*2);
			}
			
			
		}
		
		return -1;
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n,k; 	//n=Subin's location 	k=sister's location
		n=sc.nextInt();
		k=sc.nextInt();
		
		System.out.println(bfs(n,k));

	}

}
