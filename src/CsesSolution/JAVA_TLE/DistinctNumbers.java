import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
 
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
        DistinctNumbers solver = new DistinctNumbers();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class DistinctNumbers {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n;
            Set<Long> s = new TreeSet<>();
            n = in.nextInt();
            for (int i = 0; i < n; i++) {
                long input;
                input = in.nextLong();
                s.add(input);
            }
            System.out.println(s.size());
        }
 
    }
}