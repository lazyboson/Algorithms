import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

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
        CKefaAndPark solver = new CKefaAndPark();
        solver.solve(1, in, out);
        out.close();
    }

    static class CKefaAndPark {
        public void dfs(int m, int currentPark, boolean[] visited, ArrayList<ArrayList<Integer>> adj, int[] numberOfPath, int[] cats, int[] consecutiveCatsCnt) {
            //a leafnode and node is already visited
            if (adj.get(currentPark).size() == 1 && visited[adj.get(currentPark).get(0)]) {
                numberOfPath[0]++;
            }
            for (var u : adj.get(currentPark)) {
                if (!visited[u]) {
                    visited[u] = true;
                    if (cats[u] == 1) {
                        consecutiveCatsCnt[u] = consecutiveCatsCnt[currentPark] + 1;
                    }
                    if (consecutiveCatsCnt[u] <= m) {
                        dfs(m, u, visited, adj, numberOfPath, cats, consecutiveCatsCnt);
                    }
                }
            }
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            int[] cats = new int[n + 1];
            // 0 -- no cat and 1 means cat in cats[]
            for (int i = 0; i < n; i++) {
                cats[i + 1] = in.nextInt();
            }
            ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n + 1);
            for (int i = 0; i < n + 1; i++) {
                adj.add(new ArrayList<Integer>());
            }

            for (int i = 1; i <= n - 1; i++) {
                int src, dest;
                src = in.nextInt();
                dest = in.nextInt();
                adj.get(src).add(dest);
                adj.get(dest).add(src);
            }
            boolean[] visited = new boolean[n + 1];
            int[] numberOfPath = {0};
            int[] consecutiveCatsCnt = new int[n + 1];
            visited[1] = true;
            consecutiveCatsCnt[1] = cats[1];
            dfs(m, 1, visited, adj, numberOfPath, cats, consecutiveCatsCnt);
            out.println(numberOfPath[0]);
        }

    }
}

