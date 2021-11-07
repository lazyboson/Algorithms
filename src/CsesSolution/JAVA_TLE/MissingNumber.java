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
        MissingNumber solver = new MissingNumber();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class MissingNumber {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n;
            n = in.nextInt();
            boolean[] visited = new boolean[n + 1];
            for (int i = 1; i < n; i++) {
                int data;
                data = in.nextInt();
                visited[data] = true;
            }
            for (int i = 1; i <= n; i++) {
                if (visited[i] == false) {
                    System.out.println(i);
                }
            }
        }
 
    }
}