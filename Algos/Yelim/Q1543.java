package Boj;

import java.util.Scanner;

public class Q1543 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String doc = sc.nextLine(); // 전체 문서
		String findStr = sc.nextLine(); // 찾으려는 문자열
		int total = 0; 		
		
		// 찾으려는 문자열이 있는 index를 찾아 findStr.length를 더한 다음
		// (*더하는 이유 - 중복을 막으려고 이미 찾은 문자열은 제외한 상태로 다시 검색해야하니깐)
		// 더 이상 찾으려는 문자열이 없을 때까지 반복 검사
		
		for(; doc.indexOf(findStr) > -1; total ++) {		
			doc = doc.substring(doc.indexOf(findStr) + findStr.length(), doc.length());
		}				
		System.out.println(total);
	}
}