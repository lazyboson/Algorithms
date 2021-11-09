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
        BuildingRoads solver = new BuildingRoads();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class BuildingRoads {
        public void dfs(int start, boolean[] visited, ArrayList<ArrayList<Integer>> adj, int[] currentLast, boolean hasFound) {
            if (visited[start])
                return;
            visited[start] = true;
            for (var u : adj.get(start)) {
                //execute only once --
                if (u != start && !hasFound) {
                    currentLast[0] = u;
                    hasFound = true;
                }
                dfs(u, visited, adj, currentLast, hasFound);
            }
        }
 
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n + 1);
            for (int i = 0; i < n + 1; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 1; i <= m; i++) {
                int src, dest;
                src = in.nextInt();
                dest = in.nextInt();
                adj.get(src).add(dest);
                adj.get(dest).add(src);
            }
            boolean[] visited = new boolean[n + 1];
            ArrayList<ArrayList<Integer>> possibleRoads = new ArrayList<>();
            int roadsNeeded = 0;
            int preserveLast = 0;
            for (int i = 1; i < n + 1; i++) {
                if (!visited[i]) {
                    if (i != 1) {
                        ArrayList<Integer> a = new ArrayList<>();
                        a.add(preserveLast);
                        a.add(i);
                        possibleRoads.add(a);
                    }
                    roadsNeeded++;
                    int[] currentLast = {i};
                    boolean hasFound = false;
                    dfs(i, visited, adj, currentLast, hasFound);
                    preserveLast = currentLast[0];
                }
            }
            out.println(roadsNeeded - 1);
            for (ArrayList<Integer> possibleRoad : possibleRoads) {
                out.printf(possibleRoad.get(0) + " " + possibleRoad.get(1));
                out.println();
            }
 
        }
 
    }
}