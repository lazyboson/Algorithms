import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        IncreasingArray solver = new IncreasingArray();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class IncreasingArray {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n;
            n = in.nextInt();
            long[] arr = new long[n + 1];
            for (int i = 0; i < n; i++) {
                // long input;
                arr[i] = in.nextLong();
            }
            long max = 0;
            long prev = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] < prev) {
                    max += (prev - arr[i]);
                    prev = arr[i] + (prev - arr[i]);
                } else {
                    prev = arr[i];
                }
            }
            out.println(max);
        }
 
    }
}
 