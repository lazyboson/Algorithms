import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.TreeMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lazyboson
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        SumOfTwoValues solver = new SumOfTwoValues();
        solver.solve(1, in, out);
        out.close();
    }

    static class SumOfTwoValues {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int[] ans = new int[2];
            int n;
            n = in.nextInt();
            long sum;
            sum = in.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextLong();
            }
            Map<Long, Integer> m = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                if (!m.containsKey(sum - arr[i])) {
                    m.put(arr[i], i + 1);
                } else {
                    ans[0] = m.get(sum - arr[i]);
                    ans[1] = i + 1;
                    break;
                }
            }
            if (ans[0] == 0 && ans[1] == 0)
                System.out.println("IMPOSSIBLE");
            else
                System.out.printf(ans[0] + " " + ans[1]);
        }

    }
}

