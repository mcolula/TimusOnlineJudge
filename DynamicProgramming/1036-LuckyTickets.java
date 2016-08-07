import java.math.*;
import java.util.*;

public class Main {

  public static final int B = 1001;
  public static final int A =   51;

  public static BigInteger memo[][] = new BigInteger[A][B];

  public static BigInteger count(int idx, int sum) {
    if (idx <= 0 && sum == 0)
      return BigInteger.ONE ;
    if (idx <= 0)
      return BigInteger.ZERO;
    if (memo[idx][sum] != null)
      return memo[idx][sum];
    BigInteger ans = BigInteger.ZERO;
    for (int i = 0; i <= 9 && i <= sum; i++)
      ans = ans.add(count(idx - 1, sum - i));
    return memo[idx][sum] = ans;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int k = in.nextInt();
    if (k % 2 == 0)
      System.out.println(count(n, k / 2).pow(2));
    else
      System.out.println(0);
  }

}
