package Boj;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/* <정렬 조건>
1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로
3. 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력
 */
public class Q1181 {
	public static void main(String[] args) throws IOException { 

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt(); // 단어 갯수
		List<String> n = new ArrayList<String>(20010); 
		
		for(int i =0; i<T; i++){ 
			String temp= sc.next();
			if(!n.contains(temp)) 		//3번 조건
				n.add(temp); 
		}		

		//1번 조건 길이는 String x변수의 .length()로 비교해서 체크 
		// Comparator  클래스는 Main()메소드 안에서만 사용될 것이기 때문에 내부클래스로 구현함
		Comparator<String> myComparator = new Comparator<String>() { 
			public int compare(String x, String y) {
				if(x.length()>y.length()){ 
					return 1;
				} else if(x.length()==y.length()){  
					return x.compareTo(y); 
				} 				
				return -1;  // x < y 이면, (사전순 정렬)
			}
		}; 

		//2번조건은 CompareTo를 통해서 해결. 
		Collections.sort(n, myComparator);
		for(int i =0; i<n.size(); i++){ 
			System.out.println(n.get(i)); 
		} 
	}

}