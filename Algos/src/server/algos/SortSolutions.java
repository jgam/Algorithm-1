package server.algos;

import java.util.Arrays;

public class SortSolutions {
	
	public int solution(int[] citations) {
		
		int answer = 0;
		Arrays.sort(citations);
		
		for (int i = 0; i < citations.length; i++) {
			int small = Math.min(citations[i], citations.length - i);
			answer = Math.max(answer, small);
		}
		return answer;
	}
	
}
