package server.algos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BeakDFS {

	public static Queue<int[]> queue;
	public static int[][] arr;
	public static boolean[][] visited;

	public static int ROW;
	public static int COL;
	public static int result;

	public static int[] dy = { -1, 1, 0, 0 }; // 상하좌우
	public static int[] dx = { 0, 0, -1, 1 }; // 상하좌우

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		StringBuilder sb = new StringBuilder();

		int testCase = Integer.parseInt(br.readLine());

		while (testCase-- > 0) {
			st = new StringTokenizer(br.readLine());
			
			COL = Integer.parseInt(st.nextToken());
			ROW = Integer.parseInt(st.nextToken());
			
			int lineCnt = Integer.parseInt(st.nextToken());

			// 값 초기화
			queue = new LinkedList<>();
			arr = new int[ROW][COL];
			visited = new boolean[ROW][COL];
			result = 0;

			while (lineCnt-- > 0) {
				st = new StringTokenizer(br.readLine());

				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());

				arr[y][x] = 1;

				queue.offer(new int[] { y, x });
			}

			while (!queue.isEmpty()) {
				int y = queue.peek()[0];
				int x = queue.peek()[1];
				queue.poll();

				if (!visited[y][x]) {
					dfs(y, x);
					result++;
				}
			}

			sb.append(result + "\n");
		}

		System.out.println(sb.toString());
	}

	public static void dfs(int y, int x) {
		visited[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy < 0 || xx < 0 || yy >= ROW || xx >= COL)
				continue;

			if (arr[yy][xx] == 1 && !visited[yy][xx])
				dfs(yy, xx);
		}
	}

}
