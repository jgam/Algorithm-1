package algorithm;

import java.util.Scanner;

public class Question1 {

	public static void main(String[] args) {
		// 그릇을 바닥에 놓았을 때 그 높이는 10cm 
		// 그런데 두 개의 그릇을 같은 방향으로 포개면 그 높이는 5cm만 증가
		// 서로 반대방향으로 쌓이면 높이는 그릇만큼, 즉 10cm 증가
		// 입력 예시 
		// ()()() ))( => 서로 반대방향 (10x6) = 60  + 같은방향 (5x2) = 10 + 다른방향 10
		// 총 80
		
		
		Scanner sc = new Scanner(System.in);
		String su = sc.next();
		
		// 1. 문자열 쪼갠다음에 배열에 넣고 배열의 길이만큼 for문 돌려서 검사
		// 2. 0번째 배열은 무조건 +10
		// 3. 그 다음부터는 (1) 이전 배열원소와 같으면 +5  (2) 다르면 +10
		
		String a[] = su.split("");
		int height=0;
		
		for(int i=0; i<a.length; i++) {
			
			if(i==0)
				height = 10; 
			else if (a[i].equals(a[i-1]))
						height +=5;
			else
						height +=10;
			
		}
		
		System.out.println("결과는" + height);

	}

}
