package algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class Question3_1 {
	
	static int n;
	static int m;
	static int array[];
	
	public static long ans() {
		
		long current =0; // 통과돼서 누적된 예산
		long max = 0; // 최대로 출력되는 예산
		for(int i=0; i<n; i++) {
			
			if(array[i] * n < m) {
				current += array[i];						
			} else {
				max = (m-current) / (n-i);
				break;
			}
			
		}
		
		return max;
		
	}

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		array = new int[n]; // 4
		long total =0;
		
		for(int i=0; i<n; i++) {
			array[i] = in.nextInt(); // {120, 110, 140, 150}
			total +=array[i];
		}
		
		m = in.nextInt(); // 총 예산: 485
		in.close();
		
		// 정렬
		Arrays.sort(array); // 110  120  140  150
		
		// 배열 순서대로 110 *4 를 해서 예산안보다 낮으면 
		// 그 배열원소는 그대로 예산을 배정
		// n: 예산갯수(4) m: 총예산(485)
		
		if (total <= m) {
			System.out.println(array[n-1]);
		} else {
			System.out.println(ans());
		}
		
		
	}

}
