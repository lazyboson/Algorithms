import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;
 
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
        BitStrings solver = new BitStrings();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class BitStrings {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n;
            n = in.nextInt();
            BigInteger mod = new BigInteger("1000000007");
            BigInteger bigInteger = new BigInteger("2");
            BigInteger res = bigInteger.pow(n);
            out.println(res.mod(mod));
        }
 
    }
}