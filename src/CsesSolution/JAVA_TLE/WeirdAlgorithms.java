import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        WeirdAlgorithm solver = new WeirdAlgorithm();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class WeirdAlgorithm {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long n;
            n = in.nextInt();
            System.out.printf(n + " ");
            while (n != 1) {
                if (n % 2 == 0) {
                    n /= 2;
                    System.out.printf(n + " ");
                } else {
                    n = n * 3 + 1;
                    System.out.printf(n + " ");
                }
            }
            System.out.println();
        }
 
    }
}