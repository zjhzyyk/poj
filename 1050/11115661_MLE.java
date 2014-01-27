import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, s, tmp;
		int[][] mat = new int[100][100];
		int[][][][] sum = new int[100][100][100][100];
		int max = 0;
		n = sc.nextInt();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				mat[i][j] = sc.nextInt();
				sum[i][j][i][j] = mat[i][j];
			}
		for (s = 0; s < n; s++) { // height
			for (int i = 0; i < n; i++) { // width. height = s
				if (s==0&&i==0) continue;
				for (int j = 0; (j + i) < n; j++) { // start point width->x
					for (int k = 0; (k + s) < n; k++) {
						tmp = 0;
						if ((k+s)==0) continue;
						for (int l = j; l < j + i + 1; l++)
							tmp += mat[l][k +s];
						sum[j][k][j + i][k + s] = sum[j][k][j + i][k
								+ s - 1]
								+ tmp;
//						System.out.println(j+" "+k+" "+(j + i) +" "+( k +s)+" sum = " + sum[j][k][j + i][k + s]);
						if (sum[j][k][j + i][k + s] > max)
							max = sum[j][k][j + i][k + s];
					}
				}
				for (int j = 0; (j + s) < n; j++) { // start point height->x
					for (int k = 0; (k + i) < n; k++) {
						if ((j+s)==0) continue;
						tmp = 0;
						for (int l = k; l < k + i + 1; l++)
							tmp += mat[j + s][l];
						sum[j][k][j + s][k + i] = sum[j][k][j + s - 1][k
								+ i]
								+ tmp;
//						System.out.println(j+" "+k+" "+(j + s) +" "+( k + i)+" sum = " + sum[j][k][j + s][k + i]);
						if (sum[j][k][j + s][k + i] > max)
							max = sum[j][k][j + s][k + i];
					}
				}
			}
		}
		System.out.println(max);
	}
}
