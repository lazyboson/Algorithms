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
        Repetitions solver = new Repetitions();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class Repetitions {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String dna;
            dna = in.next();
            char prev = dna.charAt(0);
            int currentMax = 1;
            int maxVal = 1;
            for (int i = 1; i < dna.length(); i++) {
                if (dna.charAt(i) == prev) {
                    currentMax++;
                } else {
                    prev = dna.charAt(i);
                    currentMax = 1;
                }
                maxVal = Math.max(maxVal, currentMax);
            }
            out.println(maxVal);
        }
 
    }
}