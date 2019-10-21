using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class Program
    {
        static void Main(string[] args)
        {
            State s = new State("s", false);
            State q1 = new State("q1", true);
            State q2 = new State("q2", false);
            State r1 = new State("r1", true);
            State r2 = new State("r2", false);

            List<State> states = new List<State>() { s, q1, q2, r1, r2 };

            List<State> acceptStates = new List<State>() { q1, r1 };

            List<char> alphabet = new List<char>() { 'a', 'b' };

            State[,] deltaTable = new State[states.Count, alphabet.Count + 1];

            deltaTable[0, 0] = s;  deltaTable[0, 1] = q1; deltaTable[0, 2] = r1;
            deltaTable[1, 0] = q1; deltaTable[1, 1] = q1; deltaTable[1, 2] = q2;
            deltaTable[2, 0] = q2; deltaTable[2, 1] = q1; deltaTable[2, 2] = q2;
            deltaTable[3, 0] = r1; deltaTable[3, 1] = r2; deltaTable[3, 2] = r1;
            deltaTable[4, 0] = r2; deltaTable[4, 1] = r2; deltaTable[4, 2] = r1;

            DFA DFA = new DFA(states, s, acceptStates, alphabet, deltaTable);

            DFA.PrintDFA();

            string[] strings = { "ababa", "baba", "aababaab", "babaabaaabb", "" };

            DFA.ValidityOfStrings(strings);

            Vertex a = new Vertex("a"); Vertex h = new Vertex("h");
            Vertex b = new Vertex("b"); Vertex i = new Vertex("i");
            Vertex c = new Vertex("c"); Vertex j = new Vertex("j");
            Vertex d = new Vertex("d"); Vertex k = new Vertex("k");
            Vertex e = new Vertex("e"); Vertex l = new Vertex("l");
            Vertex f = new Vertex("f"); Vertex m = new Vertex("m");
            Vertex g = new Vertex("g"); Vertex n = new Vertex("n");

            Vertex[] vertices = { a, b, c, d, e, f, g,
                                  h, i, j, k, l, m, n };

            Edge ad = new Edge(a, d, 3);
            Edge ba = new Edge(b, a, -2);
            Edge cb = new Edge(c, b, 1);
            Edge nc = new Edge(n, c, -3);
            Edge cm = new Edge(c, m, 3);
            Edge de = new Edge(d, e, 2);
            Edge df = new Edge(d, f, 6);
            Edge dg = new Edge(d, g, -1);
            Edge dn = new Edge(d, n, -1);
            Edge ef = new Edge(e, f, 3);
            Edge fh = new Edge(f, h, -2);
            Edge gh = new Edge(g, h, 1);
            Edge gj = new Edge(g, j, 3);
            Edge hk = new Edge(h, k, -1);
            Edge ih = new Edge(i, h, -4);
            Edge ji = new Edge(j, i, 2);
            Edge jk = new Edge(j, k, 3);
            Edge lk = new Edge(l, k, 2);
            Edge ml = new Edge(m, l, -4);
            Edge nm = new Edge(n, m, 8);
            Edge nj = new Edge(n, j, 5);

            Edge[] edges = { ad, ba, cb, nc, cm, de, df,
                             dg, dn, ef, fh, gh, gj, hk,
                             ih, ji, jk, lk, ml, nm, nj };

            Graph g1 = new Graph("G1", vertices, edges);

            g1.PrintGraph("Pre Bellman-Ford");

            string result_bf = SSSPath.BellmanFord(g1, a);

            g1.PrintGraph("Post Bellman-Ford");

            Console.WriteLine(result_bf);

            GenFunctions.TextBox("Press ENTER to Exit");

            Console.Read();
        }
    }
}
