package boj_2865;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException{
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		
		float result = 0;
		float [] scores = new float[n];
		
		Map<Integer, Float> map = new HashMap<>();
		
		for(int i = 0; i < m; i++) {
			
			for(int j = 0; j < n; j++) {
				
				int num = sc.nextInt();
				float score = sc.nextFloat();
				
				if(map.containsKey(num)) {
					
					if(map.get(num)<score) {
						map.replace(num,score);
					}
					
				}else {
					map.put(num,score);
				}
			}
			
		}
		
		for(int i = 1; i <=n; i++) {
			scores[i-1] = map.get(i);		
		}
		Arrays.sort(scores);
		
		
		for(int i = scores.length-1 ; i >=scores.length-k ; i--) {
			result += scores[i];
		}
		
		System.out.format("%.1f",result);
	}
}
