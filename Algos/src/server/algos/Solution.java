package server.algos;

import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
	public int solution(int[] priorities, int location) {
		int answer = 1;
		PriorityQueue priorityQ = new PriorityQueue<>(Collections.reverseOrder());

		for (int task : priorities)
			priorityQ.add(task);

		while (!priorityQ.isEmpty()) {
			for (int i = 0; i < priorities.length; i++) {
				if (priorities[i] == (Integer)priorityQ.peek()) {
					if (i == location)
						return answer;
					priorityQ.poll();
					answer++;
				}
			}
		}
		return answer;
	}
}


