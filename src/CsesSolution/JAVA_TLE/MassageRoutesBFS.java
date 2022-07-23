import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.util.Collections;
import java.io.InputStream;
 
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        MessageRoute solver = new MessageRoute();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class MessageRoute {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n + 1);
            for (int i = 0; i < n + 1; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 0; i < m; i++) {
                int src, dest;
                src = in.nextInt();
                dest = in.nextInt();
                adj.get(src).add(dest);
                adj.get(dest).add(src);
            }
 
            boolean[] visited = new boolean[n + 1];
            int[] parent = new int[n + 1];
            int[] dist = new int[n + 1];
            dist[1] = 0;
            parent[1] = -1;
            visited[1] = true;
            Queue<Integer> queue = new LinkedList<>();
            queue.add(1);
            while (!queue.isEmpty()) {
                int node = queue.poll();
                for (var u : adj.get(node)) {
                    if (!visited[u]) {
                        visited[u] = true;
                        queue.add(u);
                        parent[u] = node;
                        dist[u] = dist[node] + 1;
                    }
                }
            }
            if (!visited[n]) {
                out.println("IMPOSSIBLE");
            } else {
                ArrayList<Integer> path = new ArrayList<>();
                for (int i = n; i != -1; i = parent[i]) {
                    path.add(i);
                }
                Collections.reverse(path);
                out.println(path.size());
                for (var u : path) {
                    out.printf("%d ", u);
                }
            }
 
        }
 
    }
 
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
    }
}
 
