package algorithm;

import java.util.Scanner;

public class Question4 {
	
	public static void main(String[] args) {
		int a, b;
	   Scanner sc = new Scanner(System.in);
	    a = sc.nextInt();
	    b = sc.nextInt();
	    int count = 0;
	 
	    if (a < b) {
	        int d = b - a;//올려야하는 온도
	        while (d > 0) {
	            if (d >= 10) {
	                d -= 10;
	                count++;
	                continue;
	 
	            }
	            else if (d >= 5) {
	                d -= 5;
	                count++;
	                continue;
	 
	            }
	            else if (d >= 1) {
	                d -= 1;
	                count++;
	                continue;
	 
	            }
	        }
	    }
	    else if (a > b) {
	        int d = a - b;//내려야하는 온도
	        while (d > 0) {
	            if (d >= 10) {
	                d -= 10;
	                count++;
	                continue;
	 
	            }
	            else if (d >= 5) {
	                d -= 5;
	                count++;
	                continue;
	 
	            }
	            else if (d >= 1) {
	                d -= 1;
	                count++;
	                continue;
	 
	            }
	        }
	    }
		
	    System.out.println(count);

	}
}