import java.util.Arrays;
import java.util.Scanner;

public class 일곱난쟁이 {
	int arr[]=new int[9];
	static int binarySearch(int []arr,int left,int right,int target) {
		if(left>right)return -1;
		
		int mid=(left+right)/2;
		
		if(target==arr[mid]) {
			return mid;
		}
		else if(target>arr[mid]) {
			return binarySearch(arr,mid+1,right,target);
		}
		else {
			return binarySearch(arr,left,mid-1,target);
		}
		
	
		
	}

	public static void main(String[] args) {
		int arr[]=new int[9];
		int arrSum=0,idx;
		Scanner sc=new Scanner(System.in);
		
		for(int i=0;i<9;i++) {
			arr[i]=sc.nextInt();
			arrSum+=arr[i];
		}
		
		Arrays.sort(arr);
		
		arrSum-=100;
		for(int i=0;i<9;i++) {
			idx=binarySearch(arr,i,arr.length-1,arrSum-arr[i]);
			
			if(idx!=-1&&arr[idx]+arr[i]==arrSum) {
				arr[idx]=-1;
				arr[i]=-1;
				break;
			}
		}
		
		for(int i=0;i<9;i++) {
			if(arr[i]!=-1)System.out.println(arr[i]);
		}
		
		
		

	}

}
