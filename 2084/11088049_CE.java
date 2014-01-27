import java.math.BigInteger;
import java.util.*;
public class main {
	public static void main(String[] args) {
		BigInteger[] ans = new BigInteger[101];
		ans[0] = new BigInteger("1");
		ans[1] = new BigInteger("1");
		ans[2] = new BigInteger("2");
		
		int tmp, t;
		for (int i = 3; i<101; i++) {
			tmp  = i-1;
			t = 0;
			ans[i] = new BigInteger("0");
			while (tmp>=0) {
				ans[i] = ans[i].add(ans[tmp--].multiply(ans[t++]));
			}
		}
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		while (n!=-1) {
			System.out.println(ans[n]);
			n = sc.nextInt();
		}
	}

}
