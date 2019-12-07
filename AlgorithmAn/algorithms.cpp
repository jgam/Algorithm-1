import java.util.*;

public class test { //완전탐색 << next_permutation로 사용할 방법 생각해보기 < 최대값들의 sum과 비교한 값들의 combination 중 max 보장방법은?
	public static int budget = 0;    // budget 입력할 예산
	public static int actNum = 0;    // budget activity 입력할 예산활동 수(size)
	public static int[] actValue = null;    // budget array  예산비용이 들어갈 배열
	public static int[] visited = null;        // budget used array 탐색한 path의 예산 값 배열
	public static int max = Integer.MIN_VALUE;    // Maximum budget 최대로 탐색한 예산 최대값
	public static String maxPath = "";            // Maximum budget passed path 예산을 최대로 탐색한 예산 배열 

	// max나 maxPath 사용하지 않고도 return을 사용한 변수 줄이는 방법 생각해보기
	// func << 입력값으로 받는 정해져있는 값 범위초과 check
  // 주어진 예산활동비용을 선택하여 진행하는 경우와 선택하지 않고 진행하는 경우로 나누는 방법으로 호출시 인덱스를 증가시킨다.
	public static void main(final String[] args) {

		final Scanner scan = new Scanner(System.in);

		budget = scan.nextInt();
		actNum = scan.nextInt();
		actValue = new int[actNum];
		visited = new int[actNum];

		for (int i = 0; i < actNum; i++) { //insert budget array
			actValue[i] = scan.nextInt();
		}
		// initialization
		final int curValue = 0;    // current budget value
		final int curIndex = 0;    // current  index
		final String curPath = ""; // print current passed path value

		func(curValue, curIndex, curPath); // 현재 가지고 있는 값 예외체크, 현재사용예산과 최대값 비교 후 max 리턴해줌
		System.out.println(max); //최대로 사용한 예산 비용 금액

		scan.close();
	}


	private static void func(final int curValue, final int curIndex, final String curPath) {

		if (curValue > budget || curIndex == actNum) {
			return;
		} // 현재 사용한 비용이 총예산보다 크거나, 정해져있는 예산활동 수와 같아지면 return

		if (max <= curValue) {
			max = curValue;
			maxPath = curPath;
		} //현재 사용예산과 최대값 비교 현재 사용예산이 크면 그 값이 최대값, 그 현재 경로를 maxpath로 지정


		// 현재 활동비용을 선택하지 않은 경우(작은경우) cur+1 후 다시 func
		func(curValue, curIndex + 1, curPath);

		// 현재 활동비용을 선택한 경우(큰 경우) curvalue+actvalue[]한 값을 curvalue 파라메타로 넘겨주어 max값과 재비교, curpath에 curindex인actvalue 추가
		func(curValue + actValue[curIndex], curIndex + 1, curPath + "," + actValue[curIndex]);
	}

}import java.util.*;

public class test { //완전탐색 << next_permutation로 사용할 방법 생각해보기 < 최대값들의 sum과 비교한 값들의 combination 중 max 보장방법은?
	public static int budget = 0;    // budget 입력할 예산
	public static int actNum = 0;    // budget activity 입력할 예산활동 수(size)
	public static int[] actValue = null;    // budget array  예산비용이 들어갈 배열
	public static int[] visited = null;        // budget used array 탐색한 path의 예산 값 배열
	public static int max = Integer.MIN_VALUE;    // Maximum budget 최대로 탐색한 예산 최대값
	public static String maxPath = "";            // Maximum budget passed path 예산을 최대로 탐색한 예산 배열 

	// max나 maxPath 사용하지 않고도 return을 사용한 변수 줄이는 방법 생각해보기
	// func << 입력값으로 받는 정해져있는 값 범위초과 check
  // 주어진 예산활동비용을 선택하여 진행하는 경우와 선택하지 않고 진행하는 경우로 나누는 방법으로 호출시 인덱스를 증가시킨다.
	public static void main(final String[] args) {

		final Scanner scan = new Scanner(System.in);

		budget = scan.nextInt();
		actNum = scan.nextInt();
		actValue = new int[actNum];
		visited = new int[actNum];

		for (int i = 0; i < actNum; i++) { //insert budget array
			actValue[i] = scan.nextInt();
		}
		// initialization
		final int curValue = 0;    // current budget value
		final int curIndex = 0;    // current  index
		final String curPath = ""; // print current passed path value

		func(curValue, curIndex, curPath); // 현재 가지고 있는 값 예외체크, 현재사용예산과 최대값 비교 후 max 리턴해줌
		System.out.println(max); //최대로 사용한 예산 비용 금액

		scan.close();
	}


	private static void func(final int curValue, final int curIndex, final String curPath) {

		if (curValue > budget || curIndex == actNum) {
			return;
		} // 현재 사용한 비용이 총예산보다 크거나, 정해져있는 예산활동 수와 같아지면 return

		if (max <= curValue) {
			max = curValue;
			maxPath = curPath;
		} //현재 사용예산과 최대값 비교 현재 사용예산이 크면 그 값이 최대값, 그 현재 경로를 maxpath로 지정


		// 현재 활동비용을 선택하지 않은 경우(작은경우) cur+1 후 다시 func
		func(curValue, curIndex + 1, curPath);

		// 현재 활동비용을 선택한 경우(큰 경우) curvalue+actvalue[]한 값을 curvalue 파라메타로 넘겨주어 max값과 재비교, curpath에 curindex인actvalue 추가
		func(curValue + actValue[curIndex], curIndex + 1, curPath + "," + actValue[curIndex]);
	}

}