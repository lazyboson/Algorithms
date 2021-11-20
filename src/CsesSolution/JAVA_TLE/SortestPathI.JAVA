import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.AbstractMap;
import java.util.AbstractCollection;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.AbstractMap.SimpleImmutableEntry;
import java.util.Comparator;
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
        ShortestRoutesI solver = new ShortestRoutesI();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class ShortestRoutesI {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            ArrayList<ArrayList<ShortestRoutesI.Pair<Integer, Integer>>> adj = new ArrayList<>(n + 1);
 
            for (int i = 0; i < n + 1; i++) {
                adj.add(new ArrayList<>());
            }
 
            for (int i = 0; i < m; i++) {
                int src, dest, w;
                src = in.nextInt();
                dest = in.nextInt();
                w = in.nextInt();
                ShortestRoutesI.Pair<Integer, Integer> p1 = new ShortestRoutesI.Pair<>(dest, w);
                adj.get(src).add(p1);
            }
            int[] distance = new int[n + 1];
            Arrays.fill(distance, Integer.MAX_VALUE);
            boolean[] visited = new boolean[n + 1];
            Dijakstras(1, n, distance, adj, visited);
            for (int i = 1; i <= n; i++) {
                out.printf(distance[i] + " ");
            }
            out.println();
        }
 
        private void Dijakstras(int i, int n, int[] distance, ArrayList<ArrayList<ShortestRoutesI.Pair<Integer, Integer>>> adj, boolean[] visited) {
            PriorityQueue<ShortestRoutesI.Pair<Integer, Integer>> queue = new PriorityQueue<>(Comparator.comparing(ShortestRoutesI.Pair::getKey));
            distance[i] = 0;
            ShortestRoutesI.Pair<Integer, Integer> p = new ShortestRoutesI.Pair<>(0, 1);
            queue.add(p);
            while (!queue.isEmpty()) {
                int a = queue.poll().getSecond();
                if (visited[a])
                    continue;
                visited[a] = true;
                for (var u : adj.get(a)) {
                    int b = u.getFirst(), w = u.getSecond();
                    if (distance[a] + w < distance[b]) {
                        distance[b] = distance[a] + w;
                        //predecessors[b] = a;
                        ShortestRoutesI.Pair<Integer, Integer> p2 = new ShortestRoutesI.Pair<>(distance[b], b);
                        queue.add(p2);
                    }
                }
            }
 
        }
 
        static class Pair<F, S> extends java.util.AbstractMap.SimpleImmutableEntry<F, S> {
            public Pair(F f, S s) {
                super(f, s);
            }
 
            public F getFirst() {
                return getKey();
            }
 
            public S getSecond() {
                return getValue();
            }
 
        }
 
    }
}