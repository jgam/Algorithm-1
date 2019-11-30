import java.util.Scanner;

public class 기억력테스트3 {

	static int []arr;
	static int binarySearch(int left,int right,int target) {
		if(left>right)return -1;
		
		int mid=(left+right)/2;
		
		if(target==arr[mid]) {
			return mid+1;
		}
		else if(target>arr[mid]) {
			return binarySearch(mid+1,right,target);
		}
		else {
			return binarySearch(left,mid-1,target);
		}
		
		
		
	}

	public static void main(String[] args) {
		int n,num;
		Scanner sc=new Scanner(System.in);
		
		n=sc.nextInt();
		arr=new int[n];
		
		for(int i=0;i<n;i++)arr[i]=sc.nextInt();
		
		n=sc.nextInt();
		
		for(int i=0;i<n;i++) {
			num=sc.nextInt();
			System.out.print(binarySearch(0,arr.length-1,num)+" ");
		}
		
		

	}


}
