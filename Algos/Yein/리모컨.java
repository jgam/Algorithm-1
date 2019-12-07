import java.util.Scanner;

public class 리모컨 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int a,b,diff,total=0;
		
		//일의 자릿수에 따른 값의 결과
		int[]opt= {0,1,2,3,2,1,2,3,3,2};
		
		a=sc.nextInt();b=sc.nextInt();
		
		diff=a<b?b-a:a-b;//a와 b의 값의 차이
		
		//일단 10을 몇번 쓸 수 있는지+
		total+=diff/10;
		diff%=10;
		
		total+=opt[diff];
		
		System.out.println(total);
		
		
	}

}
