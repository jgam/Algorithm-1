package Boj;

import java.util.Scanner;
// 2019-12-17
public class Q2966Test {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // 문제의 수 (1<=n<=100)

		String ans1[] = new String[101]; // 상근이 정답 100/3 = 1
		String ans2[] = new String[101]; // 창영이 정답 100/4 = 0
		String ans3[] = new String[101]; // 현진이 정답 100/6 = 4
		// A B C
		// B A B C
		// C C A A B B
		
		// 1. 상근이,창영이,현진이의 정답패턴에 맞게 배열 String 생성
		String repeated1 = new String(new char[33]).replace("\0", "ABC");
		repeated1 = repeated1.concat("A");
		ans1 = repeated1.split(""); // 배열에 각자의 정답을 전부 담음
		String repeated2 = new String(new char[25]).replace("\0", "BABC");
		ans2 = repeated2.split("");
		String repeated3 = new String(new char[16]).replace("\0", "CCAABB");
		repeated3 = repeated3.concat("CCAA");
		ans3 = repeated3.split("");

		// 2. 문제의 정답 입력받음 (ex. AAAABBBBB)
		String str = sc.next().toUpperCase();
		str = str.substring(0,n);
		String answer[] = new String[101];
		answer = str.split(""); // 정답 문자열도 배열에 넣음
		
		// 3. 문제 정답과 3명의 정답을 비교하여 맞은 갯수 체크
		int i = 0;
		int cnt1 =0; int cnt2=0; int cnt3=0;
		while (i < n) {
			if (answer[i].equals(ans1[i]))	// 상근이 정답 (Adrian)
				cnt1 ++;
			if (answer[i].equals(ans2[i])) // 창영이 정답 (Bruno)
				cnt2 ++;
			if (answer[i].equals(ans3[i])) // 현진이 정답 (Goran)
				cnt3 ++;
			i++;
		}
		
		// 4. 가장 많은 문제를 맞춘 갯수를 변수 max 에다 집어넣음
		int max=0;
		int[] arr = {cnt1,cnt2,cnt3};
		for(i=0; i<3; i++) {
			if(max<arr[i]) {
				max = arr[i];
			}
		}
		System.out.println(max); // 가장 많은 문제를 맞춘 사람이 몇 문제 맞췄는지 출력
		
		// 5. 최다정답갯수 max와 같은 숫자가 있는 배열 원소를 찾아 Ardian - Bruno - Goran 순서대로 출력
		for (i=0; i<3; i++) {
			if(arr[i]==max) {
				switch(i) {
				case 0:
					System.out.println("Adrian");
					break;
				case 1:
					System.out.println("Bruno");
					break;
				case 2:
					System.out.println("Goran");
					break;
				}
			}
		}
	}
}
